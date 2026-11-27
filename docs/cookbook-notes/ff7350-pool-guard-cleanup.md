# 0xff7350 BSCompoundFrustum::AllocateFromPool

<!-- tags: construct/allocation, abi/exception, wall/register-schedule -->

- Function: 0xff7350 BSCompoundFrustum::AllocateFromPool
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 210/210 aligned matching bytes
- Attempts: 5 comparisons, first local pass on comparison 2

## What differed

The allocation function carries a lock guard across a pooled return and a heap fallback. The exception cleanup uses a nullable held-lock pointer.

## Spellings tried that did not help

Making the lock storage volatile introduced a spill for the selected slot and displaced the saved guard.

## Spelling that fixed it

Keep a nullable pointer to the lock word, acquire it with interlocked compare-and-exchange, and release it with the observed store and memory fence. The same guard closes the allocator and its cleanup.
