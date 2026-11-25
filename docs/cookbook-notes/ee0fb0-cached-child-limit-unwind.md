# 0xee0fb0 NiAVObject::SavePreviousWorldTransformRecursive

<!-- tags: construct/loop, wall/control-flow, abi/exception -->

- Function: 0xee0fb0 NiAVObject::SavePreviousWorldTransformRecursive
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 175/189 aligned matching bytes; candidate size 189/189; distance 2.5
- Attempts: 6

## What differed
The function copies the current transform to the previous transform and walks non-null children after a node-view query. The child limit is captured once before recursive calls. Keeping that limit in a pointer-width signed local closed most of the loop mismatch. The final comparator still reported unwind-coverage-missing: three target unwind entries in the range had no candidate counterpart. Small branch, schedule and recursive-call diagnostics also remained, so this is not a register-only wall or a byte match.

## Spellings tried that did not help
- A 32-bit child index produced a 198-byte candidate.
- A pointer-width index that re-read the limit after recursion produced a 175-byte candidate.
- An explicit initial nonempty guard produced a 191-byte candidate.
- Caching the child limit produced the measured 189-byte near miss; an early return for a null node made no improvement.
- The comparator's automatic no-exception retry did not pass.

## Spelling that fixed it
none. Retain the captured child-limit lifetime in the next investigation, then resolve the unwind coverage and remaining call/control-flow differences without weakening the gate. These observations concern sse-steam-1-7-104 only. Source exposure was local pinned-image analysis and labelled community declarations; no sibling implementation body was inspected.
