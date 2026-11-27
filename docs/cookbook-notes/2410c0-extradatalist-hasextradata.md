# 0x2410c0 ExtraDataList::HasExtraData

<!-- tags: method/binding, abi/exception -->

- Function: 0x2410c0 ExtraDataList::HasExtraData
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: other
- Best score: 95/95 (aligned_matching_bytes)
- Attempts: 1

## What differed

All ninety-five code bytes, all twenty-seven instructions, and the C++ exception-handling unwind structures reproduced on the first attempt, but the cleanup funclet calls the out-of-line destructor `BSReadLockGuard::~BSReadLockGuard`, which has no entry in the task symbol map, so the funclet reference cannot be bound.

## Spellings tried that did not help

- Using `BSReadLockGuard` with an inline null-checked `UnlockForRead()` destructor matching existing `ExtraDataList` units (reproduced all code bytes; blocked only on funclet destructor symbol binding).

## Spelling that fixed it

none
