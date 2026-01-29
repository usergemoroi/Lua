-- ==============================================
-- MUCFY PRO HUB v5.0 - Полнофункциональный GUI
-- Автономный фреймворк. Требует инжектор с поддержкой require.
-- ==============================================

if not game:IsLoaded() then game.Loaded:Wait() end
task.wait(2)

--- Глобальный конфиг для всех модулей
local Config = {
    Aimbot = false,
    ESP = false,
    Wallhack = false,
    Speed = false,
    SpeedValue = 25,
    Jump = false,
    JumpValue = 50,
    InfJump = false,
    Noclip = false,
    AutoFarm = false,
    AutoClick = false,
    ClickSpeed = 10,
    SilentAim = false,
    FOV = 30,
    TriggerBot = false,
    Fly = false,
    FlySpeed = 2,
    Fullbright = false,
    XRay = false,
    Reacher = false,
    ReachDistance = 25,
    AntiAfk = true,
    AntiKick = true,
    UIStyle = "Dark",
}

--- Система логов
local Logs = {}
local function AddLog(text)
    local time = os.date("%H:%M:%S")
    local entry = "[" .. time .. "] " .. text
    table.insert(Logs, entry)
    if _G.MucfyLogLabel then
        _G.MucfyLogLabel.Text = table.concat(Logs, "\n")
    end
    print(entry)
end

--- Безопасное выполнение
local function SafeCall(fn, ...)
    local success, result = pcall(fn, ...)
    if not success then
        AddLog("[ОШИБКА] " .. tostring(result))
        return nil
    end
    return result
end

--- Класс для создания элементов UI
local UIClass = {}
UIClass.__index = UIClass

function UIClass.new(type, properties)
    local self = setmetatable({}, UIClass)
    self.Type = type
    self.Instance = Instance.new(type)
    if properties then
        for k, v in pairs(properties) do
            self.Instance[k] = v
        end
    end
    return self
end

function UIClass:AddChild(child)
    if child.Instance then
        child.Instance.Parent = self.Instance
    else
        child.Parent = self.Instance
    end
    return self
end

function UIClass:SetProperty(prop, value)
    self.Instance[prop] = value
    return self
end

function UIClass:SetCallback(event, func)
    if self.Instance:IsA("GuiButton") then
        self.Instance[event]:Connect(func)
    end
    return self
end

--- Создание градиентной текстуры
local function CreateGradient(color1, color2, rotation)
    local gradient = Instance.new("UIGradient")
    gradient.Color = ColorSequence.new({
        ColorSequenceKeypoint.new(0, color1),
        ColorSequenceKeypoint.new(1, color2)
    })
    gradient.Rotation = rotation or 0
    return gradient
end

--- Основное окно
local CoreGui = game:GetService("CoreGui")
local TweenService = game:GetService("TweenService")
local UserInputService = game:GetService("UserInputService")
local RunService = game:GetService("RunService")

-- Удаляем старый GUI
local oldGui = CoreGui:FindFirstChild("MucfyProHub")
if oldGui then oldGui:Destroy() end

-- ScreenGui
local ScreenGui = UIClass.new("ScreenGui", {
    Name = "MucfyProHub",
    DisplayOrder = 999,
    IgnoreGuiInset = true,
    ResetOnSpawn = false,
    ZIndexBehavior = Enum.ZIndexBehavior.Sibling,
})
ScreenGui.Instance.Parent = CoreGui

-- Основной контейнер
local MainContainer = UIClass.new("Frame", {
    Name = "MainContainer",
    Size = UDim2.new(0, 600, 0, 450),
    Position = UDim2.new(0.5, -300, 0.5, -225),
    BackgroundColor3 = Color3.fromRGB(10, 10, 18),
    BorderSizePixel = 0,
    ClipsDescendants = true,
})
:AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(0, 14)}))
:AddChild(UIClass.new("UIStroke", {
    Color = Color3.fromRGB(40, 120, 200),
    Thickness = 2,
    ApplyStrokeMode = Enum.ApplyStrokeMode.Border,
}))
ScreenGui:AddChild(MainContainer)

-- Фоновый градиент
local BgGradient = CreateGradient(
    Color3.fromRGB(15, 15, 30),
    Color3.fromRGB(5, 5, 12),
    45
)
MainContainer.Instance.BackgroundColor3 = Color3.new(1,1,1)
MainContainer.Instance.BackgroundTransparency = 0
BgGradient.Parent = MainContainer.Instance

-- Верхняя панель
local TopBar = UIClass.new("Frame", {
    Name = "TopBar",
    Size = UDim2.new(1, 0, 0, 48),
    BackgroundColor3 = Color3.fromRGB(20, 20, 35),
    BorderSizePixel = 0,
})
:AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(0, 14)}))
:SetProperty("BackgroundTransparency", 0.3)
MainContainer:AddChild(TopBar)

-- Заголовок и лого
local TitleContainer = UIClass.new("Frame", {
    Name = "TitleContainer",
    Size = UDim2.new(0, 200, 1, 0),
    BackgroundTransparency = 1,
})
TopBar:AddChild(TitleContainer)

local Logo = UIClass.new("ImageLabel", {
    Name = "Logo",
    Size = UDim2.new(0, 36, 0, 36),
    Position = UDim2.new(0, 12, 0.5, -18),
    BackgroundTransparency = 1,
    Image = "rbxassetid://10888342284", -- Заменить на актуальный ID
    ScaleType = Enum.ScaleType.Fit,
})
TitleContainer:AddChild(Logo)

local Title = UIClass.new("TextLabel", {
    Name = "Title",
    Size = UDim2.new(0, 150, 1, 0),
    Position = UDim2.new(0, 55, 0, 0),
    BackgroundTransparency = 1,
    Text = "MUCFY PRO HUB",
    TextColor3 = Color3.fromRGB(220, 240, 255),
    Font = Enum.Font.GothamBlack,
    TextSize = 20,
    TextXAlignment = Enum.TextXAlignment.Left,
})
TitleContainer:AddChild(Title)

local Subtitle = UIClass.new("TextLabel", {
    Name = "Subtitle",
    Size = UDim2.new(0, 150, 0, 18),
    Position = UDim2.new(0, 55, 0, 28),
    BackgroundTransparency = 1,
    Text = "Universal | v5.0 | Stable",
    TextColor3 = Color3.fromRGB(150, 180, 220),
    Font = Enum.Font.Gotham,
    TextSize = 12,
    TextXAlignment = Enum.TextXAlignment.Left,
})
TitleContainer:AddChild(Subtitle)

-- Кнопки управления окном
local CloseButton = UIClass.new("TextButton", {
    Name = "CloseButton",
    Size = UDim2.new(0, 32, 0, 32),
    Position = UDim2.new(1, -40, 0.5, -16),
    BackgroundColor3 = Color3.fromRGB(200, 60, 60),
    Text = "",
    AutoButtonColor = false,
})
:AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(1, 0)}))
:AddChild(UIClass.new("ImageLabel", {
    Image = "rbxassetid://10734949467",
    Size = UDim2.new(0, 18, 0, 18),
    Position = UDim2.new(0.5, -9, 0.5, -9),
    BackgroundTransparency = 1,
}))
TopBar:AddChild(CloseButton)

local MinimizeButton = UIClass.new("TextButton", {
    Name = "MinimizeButton",
    Size = UDim2.new(0, 32, 0, 32),
    Position = UDim2.new(1, -80, 0.5, -16),
    BackgroundColor3 = Color3.fromRGB(80, 80, 120),
    Text = "",
    AutoButtonColor = false,
})
:AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(1, 0)}))
:AddChild(UIClass.new("ImageLabel", {
    Image = "rbxassetid://10734950123",
    Size = UDim2.new(0, 18, 0, 18),
    Position = UDim2.new(0.5, -9, 0.5, -9),
    BackgroundTransparency = 1,
}))
TopBar:AddChild(MinimizeButton)

-- Панель вкладок
local TabContainer = UIClass.new("Frame", {
    Name = "TabContainer",
    Size = UDim2.new(0, 160, 1, -48),
    Position = UDim2.new(0, 0, 0, 48),
    BackgroundColor3 = Color3.fromRGB(18, 18, 30),
    BorderSizePixel = 0,
})
MainContainer:AddChild(TabContainer)

local TabButtonTemplate = {
    Size = UDim2.new(1, -10, 0, 42),
    BackgroundColor3 = Color3.fromRGB(30, 30, 50),
    AutoButtonColor = false,
    TextColor3 = Color3.fromRGB(200, 210, 230),
    Font = Enum.Font.GothamSemibold,
    TextSize = 14,
}

local Tabs = {
    {Name = "Combat", Icon = "🔫"},
    {Name = "Visuals", Icon = "👁"},
    {Name = "Movement", Icon = "⚡"},
    {Name = "Automation", Icon = "🤖"},
    {Name = "Players", Icon = "👥"},
    {Name = "Settings", Icon = "⚙"},
}

local TabButtons = {}
local TabFrames = {}

-- Контент вкладок
local ContentContainer = UIClass.new("Frame", {
    Name = "ContentContainer",
    Size = UDim2.new(1, -160, 1, -48),
    Position = UDim2.new(0, 160, 0, 48),
    BackgroundTransparency = 1,
    ClipsDescendants = true,
})
MainContainer:AddChild(ContentContainer)

for i, tab in ipairs(Tabs) do
    -- Кнопка вкладки
    local btn = UIClass.new("TextButton", {
        Name = tab.Name .. "TabButton",
        Position = UDim2.new(0, 5, 0, 10 + (i-1)*48),
        Text = " " .. tab.Icon .. "  " .. tab.Name,
        TextXAlignment = Enum.TextXAlignment.Left,
    })
    for k, v in pairs(TabButtonTemplate) do btn.Instance[k] = v end
    btn:AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(0, 8)}))
    TabContainer:AddChild(btn)
    TabButtons[tab.Name] = btn

    -- Контент вкладки
    local frame = UIClass.new("ScrollingFrame", {
        Name = tab.Name .. "Content",
        Size = UDim2.new(1, -10, 1, -10),
        Position = UDim2.new(0, 5, 0, 5),
        BackgroundTransparency = 1,
        BorderSizePixel = 0,
        ScrollBarThickness = 6,
        ScrollBarImageColor3 = Color3.fromRGB(60, 100, 180),
        ScrollBarImageTransparency = 0.5,
        Visible = (i == 1),
        AutomaticCanvasSize = Enum.AutomaticSize.Y,
        CanvasSize = UDim2.new(0,0,0,0),
    })
    ContentContainer:AddChild(frame)
    TabFrames[tab.Name] = frame

    -- Обработчик клика
    btn:SetCallback("MouseButton1Click", function()
        for name, f in pairs(TabFrames) do
            f:SetProperty("Visible", name == tab.Name)
        end
        for name, b in pairs(TabButtons) do
            local targetColor = (name == tab.Name) and Color3.fromRGB(50, 100, 200) or Color3.fromRGB(30, 30, 50)
            TweenService:Create(b.Instance, TweenInfo.new(0.2), {BackgroundColor3 = targetColor}):Play()
        end
    end)
end

-- Функция создания переключателя
local function CreateToggle(parent, name, default, callback)
    local container = UIClass.new("Frame", {
        Name = name .. "Toggle",
        Size = UDim2.new(1, -20, 0, 36),
        BackgroundTransparency = 1,
    })
    parent:AddChild(container)

    local label = UIClass.new("TextLabel", {
        Name = "Label",
        Size = UDim2.new(0.7, 0, 1, 0),
        BackgroundTransparency = 1,
        Text = name,
        TextColor3 = Color3.fromRGB(230, 235, 245),
        Font = Enum.Font.Gotham,
        TextSize = 15,
        TextXAlignment = Enum.TextXAlignment.Left,
    })
    container:AddChild(label)

    local toggleFrame = UIClass.new("Frame", {
        Name = "ToggleFrame",
        Size = UDim2.new(0, 50, 0, 26),
        Position = UDim2.new(1, -55, 0.5, -13),
        BackgroundColor3 = default and Color3.fromRGB(40, 180, 80) or Color3.fromRGB(80, 80, 100),
        BorderSizePixel = 0,
    })
    :AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(1, 0)}))
    container:AddChild(toggleFrame)

    local toggleCircle = UIClass.new("Frame", {
        Name = "ToggleCircle",
        Size = UDim2.new(0, 22, 0, 22),
        Position = default and UDim2.new(1, -23, 0.5, -11) or UDim2.new(0, 2, 0.5, -11),
        BackgroundColor3 = Color3.fromRGB(255, 255, 255),
        BorderSizePixel = 0,
    })
    :AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(1, 0)}))
    toggleFrame:AddChild(toggleCircle)

    local button = UIClass.new("TextButton", {
        Name = "ToggleButton",
        Size = UDim2.new(1, 0, 1, 0),
        BackgroundTransparency = 1,
        Text = "",
    })
    container:AddChild(button)

    local state = default
    button:SetCallback("MouseButton1Click", function()
        state = not state
        local targetPos = state and UDim2.new(1, -23, 0.5, -11) or UDim2.new(0, 2, 0.5, -11)
        local targetColor = state and Color3.fromRGB(40, 180, 80) or Color3.fromRGB(80, 80, 100)
        TweenService:Create(toggleCircle.Instance, TweenInfo.new(0.2), {Position = targetPos}):Play()
        TweenService:Create(toggleFrame.Instance, TweenInfo.new(0.2), {BackgroundColor3 = targetColor}):Play()
        Config[name] = state
        if callback then SafeCall(callback, state) end
        AddLog(name .. ": " .. (state and "ВКЛ" or "ВЫКЛ"))
    end)

    return container
end

-- Функция создания слайдера
local function CreateSlider(parent, name, min, max, default, callback)
    local container = UIClass.new("Frame", {
        Name = name .. "Slider",
        Size = UDim2.new(1, -20, 0, 60),
        BackgroundTransparency = 1,
    })
    parent:AddChild(container)

    local top = UIClass.new("Frame", {
        Size = UDim2.new(1, 0, 0, 24),
        BackgroundTransparency = 1,
    })
    container:AddChild(top)

    local label = UIClass.new("TextLabel", {
        Name = "Label",
        Size = UDim2.new(0.7, 0, 1, 0),
        BackgroundTransparency = 1,
        Text = name,
        TextColor3 = Color3.fromRGB(230, 235, 245),
        Font = Enum.Font.Gotham,
        TextSize = 15,
        TextXAlignment = Enum.TextXAlignment.Left,
    })
    top:AddChild(label)

    local valueLabel = UIClass.new("TextLabel", {
        Name = "ValueLabel",
        Size = UDim2.new(0.3, 0, 1, 0),
        Position = UDim2.new(0.7, 0, 0, 0),
        BackgroundTransparency = 1,
        Text = tostring(default),
        TextColor3 = Color3.fromRGB(180, 200, 255),
        Font = Enum.Font.GothamBold,
        TextSize = 15,
        TextXAlignment = Enum.TextXAlignment.Right,
    })
    top:AddChild(valueLabel)

    local sliderTrack = UIClass.new("Frame", {
        Name = "SliderTrack",
        Size = UDim2.new(1, 0, 0, 8),
        Position = UDim2.new(0, 0, 0, 32),
        BackgroundColor3 = Color3.fromRGB(50, 50, 70),
        BorderSizePixel = 0,
    })
    :AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(1, 0)}))
    container:AddChild(sliderTrack)

    local sliderFill = UIClass.new("Frame", {
        Name = "SliderFill",
        Size = UDim2.new((default - min) / (max - min), 0, 1, 0),
        BackgroundColor3 = Color3.fromRGB(60, 120, 220),
        BorderSizePixel = 0,
    })
    :AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(1, 0)}))
    sliderTrack:AddChild(sliderFill)

    local sliderButton = UIClass.new("TextButton", {
        Name = "SliderButton",
        Size = UDim2.new(0, 20, 0, 20),
        Position = UDim2.new((default - min) / (max - min), -10, 0.5, -10),
        BackgroundColor3 = Color3.fromRGB(255, 255, 255),
        Text = "",
        AutoButtonColor = false,
    })
    :AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(1, 0)}))
    :AddChild(UIClass.new("UIStroke", {
        Color = Color3.fromRGB(100, 150, 255),
        Thickness = 2,
    }))
    sliderTrack:AddChild(sliderButton)

    local dragging = false
    local function update(x)
        local relative = math.clamp((x - sliderTrack.Instance.AbsolutePosition.X) / sliderTrack.Instance.AbsoluteSize.X, 0, 1)
        local value = math.floor(min + (max - min) * relative + 0.5)
        valueLabel.Instance.Text = tostring(value)
        sliderFill.Instance.Size = UDim2.new(relative, 0, 1, 0)
        sliderButton.Instance.Position = UDim2.new(relative, -10, 0.5, -10)
        Config[name] = value
        if callback then SafeCall(callback, value) end
    end

    sliderButton.Instance.InputBegan:Connect(function(input)
        if input.UserInputType == Enum.UserInputType.MouseButton1 then
            dragging = true
        end
    end)

    sliderButton.Instance.InputEnded:Connect(function(input)
        if input.UserInputType == Enum.UserInputType.MouseButton1 then
            dragging = false
        end
    end)

    UserInputService.InputChanged:Connect(function(input)
        if dragging and input.UserInputType == Enum.UserInputType.MouseMovement then
            update(input.Position.X)
        end
    end)

    sliderTrack.Instance.InputBegan:Connect(function(input)
        if input.UserInputType == Enum.UserInputType.MouseButton1 then
            update(input.Position.X)
        end
    end)

    return container
end

-- Функция создания кнопки
local function CreateButton(parent, name, callback)
    local button = UIClass.new("TextButton", {
        Name = name .. "Button",
        Size = UDim2.new(1, -20, 0, 42),
        BackgroundColor3 = Color3.fromRGB(50, 100, 200),
        Text = name,
        TextColor3 = Color3.white,
        Font = Enum.Font.GothamBold,
        TextSize = 15,
        AutoButtonColor = false,
    })
    :AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(0, 8)}))
    :AddChild(UIClass.new("UIStroke", {
        Color = Color3.fromRGB(100, 150, 255),
        Thickness = 2,
    }))
    parent:AddChild(button)

    button:SetCallback("MouseButton1Click", function()
        if callback then SafeCall(callback) end
        AddLog("Кнопка: " .. name)
    end)

    button.Instance.MouseEnter:Connect(function()
        TweenService:Create(button.Instance, TweenInfo.new(0.2), {BackgroundColor3 = Color3.fromRGB(70, 130, 230)}):Play()
    end)

    button.Instance.MouseLeave:Connect(function()
        TweenService:Create(button.Instance, TweenInfo.new(0.2), {BackgroundColor3 = Color3.fromRGB(50, 100, 200)}):Play()
    end)

    return button
end

-- ===============================
-- ЗАПОЛНЕНИЕ ВКЛАДОК ФУНКЦИЯМИ
-- ===============================

-- Вкладка Combat
local CombatFrame = TabFrames["Combat"]
CreateToggle(CombatFrame, "Aimbot", Config.Aimbot, function(state)
    -- Реализация аимбота
end)
CreateToggle(CombatFrame, "SilentAim", Config.SilentAim, function(state)
    -- Silent Aim
end)
CreateSlider(CombatFrame, "FOV", 10, 120, Config.FOV, function(value)
    -- Изменение FOV
end)
CreateToggle(CombatFrame, "TriggerBot", Config.TriggerBot, function(state)
    -- Авто-выстрел
end)
CreateToggle(CombatFrame, "Wallhack", Config.Wallhack, function(state)
    -- Стены
end)

-- Вкладка Visuals
local VisualsFrame = TabFrames["Visuals"]
CreateToggle(VisualsFrame, "ESP", Config.ESP, function(state)
    -- ESP игроков
end)
CreateToggle(VisualsFrame, "BoxESP", false, function(state)
    -- Боксы
end)
CreateToggle(VisualsFrame, "Tracers", false, function(state)
    -- Линии к игрокам
end)
CreateToggle(VisualsFrame, "Fullbright", Config.Fullbright, function(state)
    -- Освещение
end)
CreateToggle(VisualsFrame, "XRay", Config.XRay, function(state)
    -- Рентген
end)

-- Вкладка Movement
local MovementFrame = TabFrames["Movement"]
CreateToggle(MovementFrame, "Speed", Config.Speed, function(state)
    -- Ускорение
end)
CreateSlider(MovementFrame, "SpeedValue", 16, 200, Config.SpeedValue, function(value)
    -- Значение скорости
end)
CreateToggle(MovementFrame, "Jump", Config.Jump, function(state)
    -- Высота прыжка
end)
CreateSlider(MovementFrame, "JumpValue", 50, 500, Config.JumpValue, function(value)
    -- Значение прыжка
end)
CreateToggle(MovementFrame, "InfJump", Config.InfJump, function(state)
    -- Бесконечный прыжок
end)
CreateToggle(MovementFrame, "Fly", Config.Fly, function(state)
    -- Полёт
end)
CreateSlider(MovementFrame, "FlySpeed", 1, 10, Config.FlySpeed, function(value)
    -- Скорость полёта
end)
CreateToggle(MovementFrame, "Noclip", Config.Noclip, function(state)
    -- Сквозь стены
end)

-- Вкладка Automation
local AutomationFrame = TabFrames["Automation"]
CreateToggle(AutomationFrame, "AutoFarm", Config.AutoFarm, function(state)
    -- Авто-фарм
end)
CreateToggle(AutomationFrame, "AutoClick", Config.AutoClick, function(state)
    -- Авто-клик
end)
CreateSlider(AutomationFrame, "ClickSpeed", 1, 100, Config.ClickSpeed, function(value)
    -- Скорость клика
end)
CreateToggle(AutomationFrame, "AntiAfk", Config.AntiAfk, function(state)
    -- Анти-AFK
end)
CreateButton(AutomationFrame, "Collect All Items", function()
    -- Собрать все предметы
end)

-- Вкладка Players
local PlayersFrame = TabFrames["Players"]
local PlayerList = UIClass.new("ScrollingFrame", {
    Name = "PlayerList",
    Size = UDim2.new(1, -20, 0, 200),
    BackgroundColor3 = Color3.fromRGB(20, 20, 35),
    BorderSizePixel = 0,
    ScrollBarThickness = 6,
})
:AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(0, 8)}))
PlayersFrame:AddChild(PlayerList)

local function UpdatePlayerList()
    -- Очистка
    for _, child in ipairs(PlayerList.Instance:GetChildren()) do
        if child:IsA("Frame") then child:Destroy() end
    end

    local players = game.Players:GetPlayers()
    for i, plr in ipairs(players) do
        local entry = UIClass.new("Frame", {
            Size = UDim2.new(1, -10, 0, 40),
            Position = UDim2.new(0, 5, 0, 5 + (i-1)*45),
            BackgroundColor3 = i % 2 == 0 and Color3.fromRGB(30, 30, 50) or Color3.fromRGB(25, 25, 45),
            BorderSizePixel = 0,
        })
        :AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(0, 6)}))
        PlayerList:AddChild(entry)

        local nameLabel = UIClass.new("TextLabel", {
            Size = UDim2.new(0.6, 0, 1, 0),
            BackgroundTransparency = 1,
            Text = plr.Name,
            TextColor3 = plr == game.Players.LocalPlayer and Color3.fromRGB(100, 255, 100) or Color3.fromRGB(220, 220, 240),
            Font = Enum.Font.Gotham,
            TextSize = 14,
            TextXAlignment = Enum.TextXAlignment.Left,
        })
        entry:AddChild(nameLabel)

        local teleportBtn = UIClass.new("TextButton", {
            Size = UDim2.new(0, 80, 0, 30),
            Position = UDim2.new(0.65, 0, 0.5, -15),
            BackgroundColor3 = Color3.fromRGB(70, 100, 180),
            Text = "TP",
            TextColor3 = Color3.white,
            Font = Enum.Font.GothamBold,
            TextSize = 13,
        })
        :AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(0, 6)}))
        entry:AddChild(teleportBtn)

        teleportBtn:SetCallback("MouseButton1Click", function()
            -- Телепорт к игроку
        end)
    end
    PlayerList.Instance.CanvasSize = UDim2.new(0, 0, 0, #players * 45)
end

game.Players.PlayerAdded:Connect(UpdatePlayerList)
game.Players.PlayerRemoving:Connect(UpdatePlayerList)
UpdatePlayerList()

CreateButton(PlayersFrame, "Refresh List", UpdatePlayerList)
CreateButton(PlayersFrame, "Teleport To Random", function()
    -- ТП к случайному игроку
end)

-- Вкладка Settings
local SettingsFrame = TabFrames["Settings"]
CreateToggle(SettingsFrame, "AntiKick", Config.AntiKick, function(state)
    -- Защита от кика
end)
CreateButton(SettingsFrame, "Save Settings", function()
    -- Сохранение
end)
CreateButton(SettingsFrame, "Load Settings", function()
    -- Загрузка
end)
CreateButton(SettingsFrame, "Reset All", function()
    -- Сброс
end)

local LogsLabel = UIClass.new("TextLabel", {
    Name = "LogsLabel",
    Size = UDim2.new(1, -20, 0, 100),
    Position = UDim2.new(0, 10, 0, 300),
    BackgroundColor3 = Color3.fromRGB(15, 15, 25),
    TextColor3 = Color3.fromRGB(180, 240, 180),
    Font = Enum.Font.Code,
    TextSize = 12,
    TextXAlignment = Enum.TextXAlignment.Left,
    TextYAlignment = Enum.TextYAlignment.Top,
    TextWrapped = true,
    RichText = true,
})
:AddChild(UIClass.new("UICorner", {CornerRadius = UDim.new(0, 8)}))
:AddChild(UIClass.new("UIStroke", {
    Color = Color3.fromRGB(40, 80, 40),
    Thickness = 1,
}))
SettingsFrame:AddChild(LogsLabel)
_G.MucfyLogLabel = LogsLabel.Instance
AddLog("GUI успешно загружен.")

-- Функционал окон
local minimized = false
MinimizeButton:SetCallback("MouseButton1Click", function()
    minimized = not minimized
    local targetSize = minimized and UDim2.new(0, 600, 0, 48) or UDim2.new(0, 600, 0, 450)
    TweenService:Create(MainContainer.Instance, TweenInfo.new(0.3), {Size = targetSize}):Play()
end)

CloseButton:SetCallback("MouseButton1Click", function()
    TweenService:Create(MainContainer.Instance, TweenInfo.new(0.2), {Size = UDim2.new(0, 600, 0, 0)}):Play()
    TweenService:Create(MainContainer.Instance, TweenInfo.new(0.2), {Position = UDim2.new(0.5, -300, 0.5, 0)}):Play()
    task.wait(0.25)
    ScreenGui.Instance:Destroy()
end)

-- Перетаскивание окна
local draggingWindow, dragStart, startPos
TopBar.Instance.InputBegan:Connect(function(input)
    if input.UserInputType == Enum.UserInputType.MouseButton1 then
        draggingWindow = true
        dragStart = input.Position
        startPos = MainContainer.Instance.Position
        input.Changed:Connect(function()
            if input.UserInputState == Enum.UserInputState.End then
                draggingWindow = false
            end
        end)
    end
end)

UserInputService.InputChanged:Connect(function(input)
    if draggingWindow and input.UserInputType == Enum.UserInputType.MouseMovement then
        local delta = input.Position - dragStart
        MainContainer.Instance.Position = UDim2.new(startPos.X.Scale, startPos.X.Offset + delta.X, startPos.Y.Scale, startPos.Y.Offset + delta.Y)
    end
end)

-- Горячая клавиша (например, RightShift для скрытия/показа)
local hidden = false
UserInputService.InputBegan:Connect(function(input, processed)
    if not processed and input.KeyCode == Enum.KeyCode.RightShift then
        hidden = not hidden
        MainContainer.Instance.Visible = not hidden
    end
end)

-- Запуск сервисных потоков
task.spawn(function()
    while task.wait(1) do
        if Config.AntiAfk then
            -- Анти-афк действие
            local VirtualUser = game:GetService("VirtualUser")
            VirtualUser:CaptureController()
            VirtualUser:ClickButton2(Vector2.new())
        end
    end
end)

AddLog("Система инициализирована. Горячая клавиша: RightShift")
