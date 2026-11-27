# 0x157020 ExtraDataList::RemoveExtraDataByTypeUnsafe

<!-- tags: wall/register-schedule, abi/exception -->

- Function: 0x157020 ExtraDataList::RemoveExtraDataByTypeUnsafe
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 74/315 (aligned_matching_bytes)
- Attempts: 1

## What differed

The candidate reproduced the presence-bitfield guard, memory-context scope, linked-list unlink, TLS cache invalidation, and virtual deletion, but emitted a frame-pointer-like `r11` prologue and saved an extra local copy of the previous memory context, making the function seven bytes longer than the target.

## Spellings tried that did not help

- Using a two-field `MemoryContextScope` struct (`slot` pointer and `previous` value) around the linked-list search and delete loop.

## Spelling that fixed it

none
