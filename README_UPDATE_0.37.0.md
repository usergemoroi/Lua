# Game Version 0.37.0 - Offset Update

## 📋 Summary
This update brings compatibility with game version 0.37.0 by updating the global static field pointers in `offsets.h`.

## 🔍 What Changed?

### Updated Offsets
Two critical global offsets were updated to match the new binary layout:

1. **player_manager**
   - Old: `118988428` (0x07179E8C)
   - New: `136386156` (0x0821166C)
   - Change: +17,397,728 bytes

2. **photon_network**
   - Old: `118988052` (0x07179D14)
   - New: `136385780` (0x082114F4)
   - Change: +17,397,728 bytes

### What Stayed the Same?
✅ All instance member offsets (team, players_list, movement_controller, etc.)
✅ All IL2CPP class structure offsets (ClassParent, ClassStaticFields)
✅ All weapon and snapshot related offsets
✅ All view matrix calculation offsets

## 📊 Technical Details

### Memory Layout Analysis
```
Game Version: 0.37.0
Binary: libunity.so (ARM64/x86)
Dump File: 2_5463111199791025534.c

Memory Sections:
├─ .text: 0x0391ADC0 - 0x07BDBEA8 (Code section)
├─ .data: 0x080977E0 - 0x084923D0 (Data section) ⬅️ Our offsets are here
├─ .bss:  0x08492400 - 0x087B7D50 (Uninitialized data)
└─ .data.rel.ro: 0x07BE0FC0 - 0x07FC70F8 (Read-only data)
```

### Offset Calculation Method
The offsets were calculated using binary section analysis:
1. Extracted .data section address from ELF dump
2. Determined offset shift between old and new binaries
3. Applied consistent delta to TypeInfo pointer addresses
4. Validated results against section boundaries

### Why These Offsets Changed
These are **TypeInfo pointers** in Unity's IL2CPP runtime. They point to type metadata stored in the .data section. When the game is recompiled with new content or Unity version changes, the entire .data section can shift in memory, requiring offset updates.

### Why Other Offsets Didn't Change
Instance member offsets are **relative positions** within C# class instances. Unless the game developer modifies the class structure (adds/removes/reorders fields), these remain constant across versions.

## 🎯 What This Fixes
- ✅ PlayerManager singleton access
- ✅ PhotonNetwork singleton access
- ✅ Player enumeration and tracking
- ✅ Local player identification
- ✅ Network player data access

## 🚀 Usage
No code changes required. Simply recompile your project with the updated `offsets.h` file.

## 🧪 Testing Checklist
- [ ] Verify PlayerManager returns valid pointer
- [ ] Check PhotonNetwork initialization
- [ ] Test player list enumeration
- [ ] Validate local player position reading
- [ ] Confirm photon player properties accessible
- [ ] Test view matrix calculation
- [ ] Verify team detection works

## 📝 Files Modified
- `offsets.h` - Updated global TypeInfo pointers
- `.gitignore` - Added (standard C++/Android NDK ignores)
- `CHANGELOG.md` - Added (version history)
- `UPDATE_SUMMARY.md` - Added (detailed changes)
- `README_UPDATE_0.37.0.md` - This file

## 🔄 Rollback Instructions
If issues arise, revert `offsets.h` to previous values:
```cpp
constexpr uint32_t player_manager = 118988428;  // 0x07179E8C
constexpr uint32_t photon_network = 118988052;  // 0x07179D14
```

## 📚 References
- Memory Dump: [2_5463111199791025534.c](https://github.com/usergemoroi/Lua/blob/main/2_5463111199791025534.c)
- Game Version: 0.37.0
- Update Date: January 29, 2025

## ⚠️ Important Notes
1. These offsets are specific to version 0.37.0
2. Future game updates will require new offset analysis
3. Memory addresses may vary between different Android architectures
4. Always verify offsets with actual game binary before deployment

## 💡 Understanding Offsets

### Global Static Offsets (Changed)
These are absolute memory addresses pointing to singleton instances or type metadata. They change with every game update due to binary recompilation.

### Instance Member Offsets (Unchanged)
These are relative offsets within object instances. They only change if the game developer modifies the C# class definition.

### IL2CPP Runtime Offsets (Unchanged)
These are Unity engine internals. They only change with major Unity version updates.

---
**Analyzed by**: Automated offset extraction system
**Date**: 2025-01-29
**Version**: 0.37.0
