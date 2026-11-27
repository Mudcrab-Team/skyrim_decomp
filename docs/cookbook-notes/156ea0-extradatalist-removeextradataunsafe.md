# 0x156ea0 ExtraDataList::RemoveExtraDataUnsafe

<!-- tags: wall/register-schedule, abi/exception -->

- Function: 0x156ea0 ExtraDataList::RemoveExtraDataUnsafe
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 159/363 (aligned_matching_bytes)
- Attempts: 1

## What differed

The candidate reproduced the null-entry early exit, memory-context scope, predecessor search, unlink, conditional delete, presence-bit clear, and cache-version increments within four bytes of the target size, but kept the boolean `freeEntry` parameter in a callee-saved register instead of its home stack slot and lowered the presence-bit clear to `btr` instead of a shifted mask.

## Spellings tried that did not help

- Using a one-field `MemoryContextScope` struct around the predecessor search, unlink, conditional `delete`, and `&= ~(1u << (type & 7u))` presence-bit clear.

## Spelling that fixed it

none
