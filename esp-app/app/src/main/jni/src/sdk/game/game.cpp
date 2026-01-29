#include "game.h"
#include "../../memory/memory.h"
#include "../offsets.h"
#include <cmath>
#include <cstring>

static uint32_t g_cachedLocalPlayer = 0;
static uint32_t g_cachedViewPtr1 = 0;
static uint32_t g_cachedViewPtr2 = 0;
static uint32_t g_cachedViewPtr3 = 0;

Game::Game(uint32_t libunity_base) : libunity_base_(libunity_base) {}

uint32_t Game::GetInstance(uint32_t typeInfoOffset) const {
    uint32_t typeInfoVirt = libunity_base_ + typeInfoOffset;
    uint32_t klass = c_memory_utils.read<uint32_t>(typeInfoVirt);
    
    if (klass < 0x70000000 || klass > 0xF0000000) return 0;
    
    uint32_t parent = c_memory_utils.read<uint32_t>(klass + il2cpp::ClassParent);
    
    uint32_t classForStatic = klass;
    if (parent >= 0x70000000 && parent <= 0xF0000000) {
        classForStatic = parent;
    }
    
    uint32_t statics = c_memory_utils.read<uint32_t>(classForStatic + il2cpp::ClassStaticFields);
    if (statics < 0x70000000 || statics > 0xF0000000) return 0;
    
    uint32_t instance = c_memory_utils.read<uint32_t>(statics);
    if (instance < 0x70000000 || instance > 0xF0000000) return 0;
    
    return instance;
}

uint32_t Game::GetPlayerManager() const {
    return GetInstance(off::player_manager);
}

bool Game::IsValid() const {
    uint32_t pm = GetPlayerManager();
    return pm != 0 && pm >= 0x10000;
}

Player Game::GetLocalPlayer() const {
    uint32_t pm = GetPlayerManager();
    if (!pm || pm < 0x10000) return Player(0);
    
    uint32_t localPlayer = c_memory_utils.read<uint32_t>(pm + off::local_player);
    return Player(localPlayer);
}

std::vector<Player> Game::GetPlayers() const {
    std::vector<Player> players;
    
    uint32_t pm = GetPlayerManager();
    if (!pm || pm < 0x10000) return players;
    
    uint32_t playersList = c_memory_utils.read<uint32_t>(pm + off::players_list);
    if (!playersList || playersList < 0x10000) return players;
    
    int playerCount = c_memory_utils.read<int>(playersList + 0x10);
    if (playerCount <= 0 || playerCount > 20) return players;
    
    uint32_t array = c_memory_utils.read<uint32_t>(playersList + 0xC);
    if (!array || array < 0x10000) return players;
    
    for (int i = 0; i < playerCount; i++) {
        uint32_t playerBase = c_memory_utils.read<uint32_t>(array + 0x1C + 0x10 * i);
        if (playerBase && playerBase >= 0x10000) {
            players.push_back(Player(playerBase));
        }
    }
    
    return players;
}

bool Game::ReadViewMatrix(Matrix& vm) const {
    Player local = GetLocalPlayer();
    if (!local.IsValid()) return false;
    
    uint32_t localBase = local.GetBase();
    if (!localBase || localBase < 0x10000) return false;

    if (localBase != g_cachedLocalPlayer) {
        g_cachedViewPtr1 = 0;
        g_cachedViewPtr2 = 0;
        g_cachedViewPtr3 = 0;
        g_cachedLocalPlayer = localBase;
    }

    if (!g_cachedViewPtr1 || g_cachedViewPtr1 < 0x10000) {
        g_cachedViewPtr1 = c_memory_utils.read<uint32_t>(localBase + off::vm_step1);
        g_cachedViewPtr2 = 0;
        g_cachedViewPtr3 = 0;
    }

    if (!g_cachedViewPtr1 || g_cachedViewPtr1 < 0x10000) return false;

    if (!g_cachedViewPtr2) {
        g_cachedViewPtr2 = c_memory_utils.read<uint32_t>(g_cachedViewPtr1 + off::vm_step2);
    }
    if (!g_cachedViewPtr2 || g_cachedViewPtr2 < 0x10000) {
        g_cachedViewPtr2 = 0;
        g_cachedViewPtr1 = 0;
        return false;
    }

    if (!g_cachedViewPtr3) {
        g_cachedViewPtr3 = c_memory_utils.read<uint32_t>(g_cachedViewPtr2 + off::vm_step3);
    }
    if (!g_cachedViewPtr3 || g_cachedViewPtr3 < 0x10000) {
        g_cachedViewPtr3 = 0;
        g_cachedViewPtr2 = 0;
        return false;
    }

    float matrix[16];
    if (!memory_utils::read_memory((void*)(uintptr_t)(g_cachedViewPtr3 + off::vm_final), matrix, 64)) {
        g_cachedViewPtr3 = 0;
        g_cachedViewPtr2 = 0;
        return false;
    }

    for (int i = 0; i < 16; i++) {
        if (std::isnan(matrix[i]) || std::abs(matrix[i]) > 100000.0f) {
            g_cachedViewPtr3 = 0;
            g_cachedViewPtr2 = 0;
            return false;
        }
    }

    memcpy(&vm.m[0][0], matrix, 64);
    return true;
}

Vec3 Game::GetLocalPosition() const {
    Player local = GetLocalPlayer();
    return local.GetPosition();
}

uint8_t Game::GetLocalTeam() const {
    Player local = GetLocalPlayer();
    return local.GetTeam();
}
