# Changelog

## Version 0.37.0 - 2025-01-29

### Updated
- **offsets.h**: Updated global static field pointers for game version 0.37.0
  - `player_manager`: 118988428 → 136386156 (0x07179E8C → 0x0821166C)
  - `photon_network`: 118988052 → 136385780 (0x07179D14 → 0x082114F4)

### Analysis Details
- Memory dump analyzed: `2_5463111199791025534.c`
- Binary section changes:
  - .data section relocated from ~0x07000000 to 0x080977E0
  - Calculated offset shift: +0x17397E0 (~24.4 MB forward)
- Instance member offsets remain unchanged (no C# class structure modifications)
- IL2CPP runtime offsets remain stable

### Technical Notes
The offset update was performed by analyzing the memory dump's ELF structure:
- Identified .data section relocation in the new binary
- Calculated relative offsets from old base address
- Applied shift to determine new TypeInfo pointer locations
- Verified new addresses fall within valid .data section range (0x080977E0 - 0x084923D0)

### Unchanged Offsets
All instance member offsets remain the same:
- team, players_list, local_player, photon_player
- movement_controller, weaponry_controller, weapon_controller
- snapshot, vm_step1/2/3/final
- photon_name, custom_properties, weapon_parameters
- All IL2CPP class structure offsets (ClassParent, ClassStaticFields)
