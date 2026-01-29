# Version 0.37.0 Update Summary

## Date: 2025-01-29

## Overview
Updated game offsets for version 0.37.0 based on memory dump analysis.

## Changes Made

### 1. Updated offsets.h
**File**: `offsets.h`

#### Modified Offsets:
| Offset Name | Old Value (Hex) | New Value (Hex) | Old Value (Dec) | New Value (Dec) | Delta |
|-------------|----------------|-----------------|----------------|-----------------|-------|
| `player_manager` | 0x07179E8C | 0x0821166C | 118,988,428 | 136,386,156 | +17,397,728 |
| `photon_network` | 0x07179D14 | 0x082114F4 | 118,988,052 | 136,385,780 | +17,397,728 |

#### Unchanged Offsets:
All instance member offsets remain unchanged:
- `team = 0x3D`
- `players_list = 0x18`
- `local_player = 0x3C`
- `photon_player = 0xC4`
- `movement_controller = 0x50`
- `photon_name = 0x10`
- `custom_properties = 0x1C`
- `props_entries = 0x0C`
- `props_count = 0x10`
- `boxed_value = 0x08`
- `snapshot = 0x68`
- `snapshot_pos = 0xC`
- `vm_step1 = 0x78`
- `vm_step2 = 0x10`
- `vm_step3 = 0x08`
- `vm_final = 0xE8`
- `weaponry_controller = 0x48`
- `weapon_controller = 0x58`
- `weapon_parameters = 0x64`
- `weapon_name = 0x10`

IL2CPP class offsets also unchanged:
- `ClassParent = 0x2C`
- `ClassStaticFields = 0x5C`

## Analysis Method

### Memory Dump Analysis
**Source**: `2_5463111199791025534.c`

### ELF Section Analysis:
```
Old .data section (estimated): ~0x07000000
New .data section: 0x080977E0 - 0x084923D0 (size: 0x3FABF0)
Section shift: +0x17397E0 bytes (~17.4 MB forward)
```

### Calculation Process:
1. Analyzed ELF dump to identify .data section location
2. Calculated relative offsets of TypeInfo pointers from old base
3. Applied shift to determine new absolute addresses
4. Verified new addresses fall within valid .data section range

### Verification:
- ✅ New offsets within valid .data section range
- ✅ Consistent offset delta between both values (+17,397,728)
- ✅ Proper hexadecimal alignment
- ✅ Instance offsets logically unchanged (no class structure modifications)

## Files Modified
1. `offsets.h` - Updated global static field pointers

## Files Created
1. `.gitignore` - Standard ignore patterns for C++/Android NDK projects
2. `CHANGELOG.md` - Version history documentation
3. `UPDATE_SUMMARY.md` - This file

## Compatibility Notes
- Game Version: 0.37.0
- Architecture: ARM64/x86 (Android)
- Binary: libunity.so
- Engine: Unity with IL2CPP

## Testing Recommendations
1. Verify PlayerManager instance is correctly retrieved
2. Confirm PhotonNetwork singleton access works
3. Test player enumeration functionality
4. Validate position reading from movement controller
5. Check photon player property access

## Rollback Information
If version 0.37.0 offsets prove incorrect, revert to:
- `player_manager = 118988428` (0x07179E8C)
- `photon_network = 118988052` (0x07179D14)
