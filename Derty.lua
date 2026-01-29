--[[
    Анализ и решение ошибок консоли Roblox/Delta.
    Полный отладочный и инжекционный скрипт.
]]

--- ШАГ 1: Диагностика среды
local function DiagnoseEnvironment()
    local diagnostics = {
        GameLoaded = game:IsLoaded(),
        PlaceId = game.PlaceId,
        JobId = game.JobId,
        Players = #game.Players:GetPlayers(),
        Executor = _G.executor_name or "Unknown",
        Syn = (syn and true) or false,
        ProtectGui = (get_hidden_gui or protect_gui or false),
        ConsoleErrors = 0
    }

    -- Проверяем, доступна ли старая консоль (для вывода наших логов)
    local rconsole = rconsole or print
    rconsole("=== DIAGNOSTIC REPORT ===")
    for k, v in pairs(diagnostics) do
        rconsole(k .. ": " .. tostring(v))
    end

    -- Сканирование на наличие подозрительных скриптов (которые могут вызывать ошибки)
    local suspiciousScripts = {}
    for _, obj in pairs(game:GetDescendants()) do
        if obj:IsA("Script") or obj:IsA("LocalScript") or obj:IsA("ModuleScript") then
            if #obj.Name > 20 and not obj.Name:match("%s") then -- Длинные имена без пробелов
                table.insert(suspiciousScripts, {Name = obj.Name, Path = obj:GetFullName(), Class = obj.ClassName})
            end
        end
    end

    if #suspiciousScripts > 0 then
        rconsole("\n[WARN] Найдены скрипты с подозрительными именами (возможно, инжект):")
        for _, s in ipairs(suspiciousScripts) do
            rconsole(string.format("  %s (%s) at %s", s.Name, s.Class, s.Path))
        end
    end

    return diagnostics
end

--- ШАГ 2: Перехват ошибок компиляции и выполнения
-- Сохраняем оригинальные обработчики
local originalErrorHandler
if _G.originalErrorHandler == nil then
    originalErrorHandler = function(message, traceback)
        -- Это глобальный обработчик ошибок, если он есть
        return message, traceback
    end
    _G.originalErrorHandler = originalErrorHandler
end

-- Устанавливаем наш перехватчик для вывода в управляемую консоль
local errorLog = {}
local function EnhancedErrorHandler(message, traceback, customData)
    local errorId = #errorLog + 1
    local entry = {
        Id = errorId,
        Message = tostring(message),
        Traceback = tostring(traceback),
        Timestamp = os.time(),
        Data = customData,
        IsSyntax = (tostring(message):find("expected") and true) or false
    }
    table.insert(errorLog, entry)

    -- Выводим в удобочитаемом формате
    local output = string.format(
        "\n[ERROR #%d] %s\nTraceback:\n%s\n",
        errorId,
        entry.Message,
        entry.Traceback
    )
    if rconsole then
        rconsole(output)
    else
        warn(output)
    end

    -- Не прерываем выполнение, если это не критично
    return message, traceback
end

-- Применяем перехватчик
pcall(function()
    if debug and debug.traceback then
        local oldTraceback = debug.traceback
        debug.traceback = function(message, level)
            local trace = oldTraceback(message, level)
            EnhancedErrorHandler(message, trace, {Level = level})
            return trace
        end
    end
end)

--- ШАГ 3: Очистка мусорных скриптов, вызывающих ошибки
-- Функция для безопасного удаления скриптов с ошибками компиляции
local function CleanupCorruptedScripts()
    local cleaned = 0
    local skipped = 0

    -- Обходим все объекты в DataModel
    for _, obj in pairs(game:GetDescendants()) do
        if obj:IsA("Script") or obj:IsA("LocalScript") or obj:IsA("ModuleScript") then
            local shouldRemove = false

            -- Критерий 1: Имя состоит из случайных символов (например, gYWRVqVoVsRUkgnua)
            if obj.Name:match("^[a-zA-Z0-9]+$") and #obj.Name >= 15 and not obj.Name:match("[aeiouyAEIOUY]") then
                shouldRemove = true
            end

            -- Критерий 2: Скрипт уже вызвал ошибку (проверяем по логу)
            for _, err in ipairs(errorLog) do
                if err.Message:find(obj.Name) then
                    shouldRemove = true
                    break
                end
            end

            if shouldRemove then
                local success = pcall(function()
                    -- Пытаемся остановить, если выполняется
                    if obj:IsA("Script") and obj.Disabled == false then
                        obj.Disabled = true
                    end
                    obj:Destroy()
                end)
                if success then
                    cleaned = cleaned + 1
                else
                    skipped = skipped + 1
                end
            end
        end
    end

    if rconsole then
        rconsole(string.format("\n[Cleanup] Удалено скриптов: %d, Не удалось: %d", cleaned, skipped))
    end
    return cleaned
end

--- ШАГ 4: Внедрение стабильного загрузчика GUI (альтернатива повреждённому коду)
local function InjectStableGUI()
    -- Сначала чистим возможные остатки
    local coreGui = game:GetService("CoreGui")
    local oldGui = coreGui:FindFirstChild("MucfyStableGUI")
    if oldGui then oldGui:Destroy() end

    -- Создаём максимально простой и стабильный GUI
    local screenGui = Instance.new("ScreenGui")
    screenGui.Name = "MucfyStableGUI"
    screenGui.DisplayOrder = 999
    screenGui.ResetOnSpawn = false
    screenGui.IgnoreGuiInset = true
    screenGui.ZIndexBehavior = Enum.ZIndexBehavior.Sibling

    local mainFrame = Instance.new("Frame")
    mainFrame.Name = "Main"
    mainFrame.Size = UDim2.new(0, 400, 0, 300)
    mainFrame.Position = UDim2.new(0.5, -200, 0.5, -150)
    mainFrame.BackgroundColor3 = Color3.fromRGB(25, 25, 35)
    mainFrame.BorderSizePixel = 0
    mainFrame.ClipsDescendants = true

    local corner = Instance.new("UICorner")
    corner.CornerRadius = UDim.new(0, 10)
    corner.Parent = mainFrame

    local topBar = Instance.new("Frame")
    topBar.Name = "TopBar"
    topBar.Size = UDim2.new(1, 0, 0, 40)
    topBar.BackgroundColor3 = Color3.fromRGB(35, 35, 50)
    topBar.BorderSizePixel = 0
    topBar.Parent = mainFrame

    local title = Instance.new("TextLabel")
    title.Name = "Title"
    title.Size = UDim2.new(1, -80, 1, 0)
    title.Position = UDim2.new(0, 10, 0, 0)
    title.BackgroundTransparency = 1
    title.Text = "Mucfy Stable Interface"
    title.TextColor3 = Color3.fromRGB(220, 220, 255)
    title.Font = Enum.Font.GothamBold
    title.TextSize = 16
    title.TextXAlignment = Enum.TextXAlignment.Left
    title.Parent = topBar

    local closeBtn = Instance.new("TextButton")
    closeBtn.Name = "Close"
    closeBtn.Size = UDim2.new(0, 30, 0, 30)
    closeBtn.Position = UDim2.new(1, -40, 0.5, -15)
    closeBtn.BackgroundColor3 = Color3.fromRGB(200, 60, 60)
    closeBtn.Text = "X"
    closeBtn.Font = Enum.Font.GothamBold
    closeBtn.TextColor3 = Color3.white
    closeBtn.TextSize = 14
    closeBtn.Parent = topBar

    local uiCorner = Instance.new("UICorner")
    uiCorner.CornerRadius = UDim.new(0, 6)
    uiCorner.Parent = closeBtn

    -- Контейнер для кнопок
    local buttonContainer = Instance.new("ScrollingFrame")
    buttonContainer.Name = "Buttons"
    buttonContainer.Size = UDim2.new(1, -20, 1, -60)
    buttonContainer.Position = UDim2.new(0, 10, 0, 50)
    buttonContainer.BackgroundTransparency = 1
    buttonContainer.BorderSizePixel = 0
    buttonContainer.ScrollBarThickness = 6
    buttonContainer.AutomaticCanvasSize = Enum.AutomaticSize.Y
    buttonContainer.Parent = mainFrame

    -- Список функций
    local functionsList = {
        {"Teleport To Player", function()
            -- Пример функции
            print("Teleport function called")
        end},
        {"ESP Toggle", function()
            print("ESP toggled")
        end},
        {"Speed Hack", function()
            print("Speed hack activated")
        end},
        {"Clean Console Errors", function()
            CleanupCorruptedScripts()
        end},
        {"Diagnose", function()
            DiagnoseEnvironment()
        end}
    }

    -- Создаём кнопки
    for i, funcData in ipairs(functionsList) do
        local name, func = funcData[1], funcData[2]
        local btn = Instance.new("TextButton")
        btn.Name = "Btn_" .. name:gsub("%s+", "")
        btn.Size = UDim2.new(1, 0, 0, 40)
        btn.Position = UDim2.new(0, 0, 0, (i-1)*45)
        btn.BackgroundColor3 = Color3.fromRGB(50, 50, 80)
        btn.Text = name
        btn.Font = Enum.Font.Gotham
        btn.TextColor3 = Color3.fromRGB(240, 240, 255)
        btn.TextSize = 14
        btn.AutoButtonColor = true

        local btnCorner = Instance.new("UICorner")
        btnCorner.CornerRadius = UDim.new(0, 8)
        btnCorner.Parent = btn

        btn.MouseButton1Click:Connect(function()
            pcall(func)
        end)

        btn.Parent = buttonContainer
    end

    -- Лог ошибок внутри GUI
    local logFrame = Instance.new("ScrollingFrame")
    logFrame.Name = "ErrorLog"
    logFrame.Size = UDim2.new(1, -20, 0, 100)
    logFrame.Position = UDim2.new(0, 10, 1, -110)
    logFrame.BackgroundColor3 = Color3.fromRGB(15, 15, 25)
    logFrame.BorderSizePixel = 0
    logFrame.ScrollBarThickness = 4
    logFrame.AutomaticCanvasSize = Enum.AutomaticSize.Y
    logFrame.Visible = false
    logFrame.Parent = mainFrame

    local logLabel = Instance.new("TextLabel")
    logLabel.Name = "LogLabel"
    logLabel.Size = UDim2.new(1, -10, 0, 300)
    logLabel.Position = UDim2.new(0, 5, 0, 5)
    logLabel.BackgroundTransparency = 1
    logLabel.Text = "Ошибок нет."
    logLabel.TextColor3 = Color3.fromRGB(180, 180, 220)
    logLabel.Font = Enum.Font.Code
    logLabel.TextSize = 11
    logLabel.TextXAlignment = Enum.TextXAlignment.Left
    logLabel.TextYAlignment = Enum.TextYAlignment.Top
    logLabel.TextWrapped = true
    logLabel.Parent = logFrame

    -- Кнопка показа лога
    local toggleLogBtn = Instance.new("TextButton")
    toggleLogBtn.Name = "ToggleLog"
    toggleLogBtn.Size = UDim2.new(0, 120, 0, 30)
    toggleLogBtn.Position = UDim2.new(0.5, -60, 1, -150)
    toggleLogBtn.BackgroundColor3 = Color3.fromRGB(60, 60, 100)
    toggleLogBtn.Text = "Показать логи ошибок"
    toggleLogBtn.Font = Enum.Font.Gotham
    toggleLogBtn.TextColor3 = Color3.white
    toggleLogBtn.TextSize = 12
    toggleLogBtn.Parent = mainFrame

    toggleLogBtn.MouseButton1Click:Connect(function()
        logFrame.Visible = not logFrame.Visible
        if logFrame.Visible then
            local logText = "Последние ошибки:\n"
            for i = math.max(1, #errorLog - 5), #errorLog do
                local err = errorLog[i]
                logText = logText .. string.format("#%d: %s\n", err.Id, err.Message:sub(1, 50))
            end
            logLabel.Text = logText
        end
    end)

    -- Функционал закрытия
    closeBtn.MouseButton1Click:Connect(function()
        screenGui:Destroy()
    end)

    -- Функционал перетаскивания
    local dragging, dragStart, startPos
    topBar.InputBegan:Connect(function(input)
        if input.UserInputType == Enum.UserInputType.MouseButton1 then
            dragging = true
            dragStart = input.Position
            startPos = mainFrame.Position
            input.Changed:Connect(function()
                if input.UserInputState == Enum.UserInputState.End then
                    dragging = false
                end
            end)
        end
    end)

    game:GetService("UserInputService").InputChanged:Connect(function(input)
        if dragging and input.UserInputType == Enum.UserInputType.MouseMovement then
            local delta = input.Position - dragStart
            mainFrame.Position = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
        end
    end)

    -- Финальная сборка
    mainFrame.Parent = screenGui
    screenGui.Parent = coreGui

    return screenGui
end

--- ШАГ 5: Патч для конкретных ошибок из лога
local function ApplySpecificPatches()
    -- 1. Патч для ошибки "attempt to index string with 'Steal'"
    -- Ищем строку, к которой пытаются обратиться через .Steal
    for _, obj in pairs(game:GetDescendants()) do
        if obj:IsA("StringValue") then
            if obj.Value and type(obj.Value) == "string" and obj.Value:find("Steal") then
                -- Заменяем проблемную строку на пустую таблицу или nil
                obj.Value = ""
                warn("[Patch] Исправлена строка в " .. obj:GetFullName())
            end
        end
    end

    -- 2. Патч для ошибки "Locked is not a valid member of BillboardGui"
    -- Отключаем проблемный скрипт или модифицируем его
    local targetScript = game:GetService("ReplicatedStorage"):FindFirstChild("PlotClient", true)
    if targetScript and targetScript:IsA("ModuleScript") then
        -- Можно попытаться загрузить и модифицировать исходный код
        local success, source = pcall(function()
            return require(targetScript)
        end)
        if success and type(source) == "table" then
            -- Если модуль загружается, добавляем заглушку для проблемного метода
            if source.UpdatePurchaseBlockedLabel then
                local original = source.UpdatePurchaseBlockedLabel
                source.UpdatePurchaseBlockedLabel = function(...)
                    local args = {...}
                    -- Обходим обращение к Locked
                    if args[1] and args[1].Locked then
                        args[1].Locked = nil
                    end
                    return original(unpack(args))
                end
                warn("[Patch] Module PlotClient patched.")
            end
        end
    end

    -- 3. Патч для скриптов с синтаксическими ошибками (<eof>)
    -- Находим и либо исправляем, либо удаляем
    local scriptsToCheck = {
        "ReplicatedStorage.Packages.Synchronizer.Channel",
        -- Добавить другие по имени из лога
    }

    for _, path in ipairs(scriptsToCheck) do
        local obj = game:GetService("ReplicatedStorage")
        for part in path:gmatch("[^.]+") do
            obj = obj:FindFirstChild(part)
            if not obj then break end
        end
        if obj and (obj:IsA("Script") or obj:IsA("ModuleScript")) then
            -- Пытаемся получить исходник
            local src = obj.Source
            if src and src:find("Steal") then
                -- Заменяем проблемную конструкцию
                local fixedSrc = src:gsub("%.Steal", "['Steal']")
                -- Внимание: Изменение .Source напрямую может не сработать, это зависит от контекста
                -- Альтернатива: создать новый скрипт-заглушку
                local stub = Instance.new("ModuleScript")
                stub.Name = obj.Name .. "_Patched"
                stub.Source = "return {} -- Заглушка"
                stub.Parent = obj.Parent
                obj.Disabled = true
                warn("[Patch] Script " .. path .. " disabled and replaced with stub.")
            end
        end
    end
end

--- ШАГ 6: Основная процедура запуска
local function Main()
    if rconsole then rconsole.clear() end

    print("\n=== MUCFY DEBUG & FIX UTILITY ===")
    print("Запуск диагностики...")

    local diag = DiagnoseEnvironment()
    print(string.format("Игра: %s, Место: %d", diag.GameLoaded and "Загружена" : "Не загружена", diag.PlaceId))

    print("Очистка повреждённых скриптов...")
    local cleaned = CleanupCorruptedScripts()
    print("Удалено: " .. cleaned)

    print("Применение патчей...")
    ApplySpecificPatches()

    print("Внедрение стабильного GUI...")
    local gui = InjectStableGUI()
    if gui then
        print("GUI успешно создан. Используйте кнопки для управления.")
    else
        print("Ошибка при создании GUI.")
    end

    -- Запуск мониторинга новых ошибок
    local errorMonitor = game:GetService("ScriptContext").Error
    if errorMonitor then
        errorMonitor:Connect(function(message, trace, script)
            EnhancedErrorHandler(message, trace, {Script = script})
        end)
        print("Мониторинг ошибок активирован.")
    end

    print("\n=== СИСТЕМА АКТИВНА ===")
    print("Горячие клавиши:")
    print("  F9 - Показать/скрыть GUI")
    print("  F10 - Очистить консольные ошибки")
    print("  F11 - Перезапустить утилиту")

    -- Горячие клавиши
    local ui = game:GetService("UserInputService")
    ui.InputBegan:Connect(function(input, processed)
        if processed then return end

        if input.KeyCode == Enum.KeyCode.F9 then
            local gui = game:GetService("CoreGui"):FindFirstChild("MucfyStableGUI")
            if gui then
                gui.Enabled = not gui.Enabled
            end
        elseif input.KeyCode == Enum.KeyCode.F10 then
            errorLog = {}
            if rconsole then rconsole.clear() end
            print("Консоль очищена.")
        elseif input.KeyCode == Enum.KeyCode.F11 then
            -- "Перезапуск" через повторное выполнение
            loadstring(game:HttpGetAsync("https://pastebin.com/raw/YourScriptCodeHere"))()
        end
    end)

    return true
end

-- Запуск основной функции с защитой
local success, err = pcall(Main)
if not success then
    warn("[CRITICAL] Ошибка запуска утилиты: " .. err)
    -- Последняя попытка: простой GUI
    pcall(InjectStableGUI)
end
