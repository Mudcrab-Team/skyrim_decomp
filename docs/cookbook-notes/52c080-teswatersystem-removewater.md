# 0x52c080 TESWaterSystem::RemoveWater

<!-- tags: method/diagnostic -->

- Function: 0x52c080 TESWaterSystem::RemoveWater
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 509/986 (aligned_matching_bytes)
- Attempts: 5

## What differed

Passing `const NiPointer<NiRefObject>&` to `Functioneec430` and placing `LockGuard` in an inner scope before `return false;` gave the expected frame size and unwind guards and `982` of `986` bytes (`509` best aligned), differing only in index vs pointer caching during `waterObjects` lookup.

## Spellings tried that did not help

- Passing `NiPointer<NiRefObject>` by value suppressed caller-side temporary destruction.
- Indexing `waterObjects.data[objIdx]` twice before vs once at loop entry swapped array base caching and changed length (`998` vs `982` bytes).

## Spelling that fixed it

none
