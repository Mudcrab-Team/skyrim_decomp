# 0x30da20 TESWorldSpace::sub_1402B2A50

<!-- tags: wall/register-schedule, construct/float -->

- Function: 0x30da20 TESWorldSpace::sub_1402B2A50
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 107/158 (aligned_matching_bytes)
- Attempts: 5

## What differed

The control flow and instruction count reproduced closely (47 instructions, 159 vs 158 bytes), but the compiler spilled the incoming position pointer into a scratch register and kept the `this` pointer in its original parameter register until the first fixed-center load, swapping the integer registers used for the cell coordinate difference and the fixed-center fields.

## Spellings tried that did not help

- Early return when the fixed-dimensions flag is clear, computing both floored coordinates before the checks.
- Guarded `if` around the fixed-dimensions checks with separate `FloorCoord` and `FloorToCell` inline helpers.
- Single `bool result = true` exit (cookbook rule 34), which swapped which input pointer was copied into the scratch register.
- Combining both axis checks with logical AND versus logical OR and explicit casts to signed 32-bit integers.

## Spelling that fixed it

none
