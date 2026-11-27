# 0x30eef0 TESWorldSpace::sub_1402B3EE0

<!-- tags: wall/control-flow, wall/register-schedule -->

- Function: 0x30eef0 TESWorldSpace::sub_1402B3EE0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 137/186 (aligned_matching_bytes)
- Attempts: 4

## What differed

The body of the hash-map lookup reproduced, including key packing and bucket traversal, but the target shrink-wraps two callee-saved home-slot saves inside the non-null map branch and keeps a separate short epilogue for the null-map early exit. The candidate always saved both registers in the prologue and merged the null-map exit with the not-found exit.

## Spellings tried that did not help

- Direct inlined bucket loop with early return when the map pointer is null, both with zero-initialized and uninitialized coordinate locals.
- Moving the lookup into an inline `GetAt(key, outValue)` member helper returning `bool`.
- Using a single result pointer initialized to null before the non-null map check.

## Spelling that fixed it

none
