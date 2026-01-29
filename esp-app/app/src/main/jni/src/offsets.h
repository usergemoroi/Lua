#pragma once
#include <cstdint>

// Version: 0.37.0
// Updated: 2025-01-29
// Based on memory dump analysis: 2_5463111199791025534.c

namespace off {
    // Global static field pointers (TypeInfo addresses)
    // These change between game versions due to binary layout changes
    constexpr uint32_t player_manager = 136386156;  // 0x0821166C (was 118988428)
    constexpr uint32_t photon_network = 136385780;  // 0x082114F4 (was 118988052)
    
    // Instance member offsets
    // These are relative offsets within C# class instances
    // Usually stable across versions unless class structure changes
    constexpr uint32_t team = 0x3D;
    constexpr uint32_t players_list = 0x18;
    constexpr uint32_t local_player = 0x3C;
    constexpr uint32_t photon_player = 0xC4;
    constexpr uint32_t movement_controller = 0x50;
    constexpr uint32_t photon_name = 0x10;
    constexpr uint32_t custom_properties = 0x1C;
    constexpr uint32_t props_entries = 0x0C;
    constexpr uint32_t props_count = 0x10;
    constexpr uint32_t boxed_value = 0x08;
    constexpr uint32_t snapshot = 0x68;
    constexpr uint32_t snapshot_pos = 0xC;
    constexpr uint32_t vm_step1 = 0x78;
    constexpr uint32_t vm_step2 = 0x10;
    constexpr uint32_t vm_step3 = 0x08;
    constexpr uint32_t vm_final = 0xE8;
    constexpr uint32_t weaponry_controller = 0x48;
    constexpr uint32_t weapon_controller = 0x58;
    constexpr uint32_t weapon_parameters = 0x64;
    constexpr uint32_t weapon_name = 0x10;
}

// IL2CPP runtime class structure offsets
// These are internal to Unity's IL2CPP implementation
// Generally stable across game versions (changes only with Unity engine updates)
namespace il2cpp {
    constexpr uint32_t ClassParent = 0x2C;
    constexpr uint32_t ClassStaticFields = 0x5C;
}
