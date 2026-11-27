# 0x6a7b30 TESObjectREFR::ComputeForwardLength

<!-- tags: wall/register-schedule, construct/float -->

- Function: 0x6a7b30 TESObjectREFR::ComputeForwardLength
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 135/150 (aligned_matching_bytes)
- Attempts: 5

## What differed

The candidate reproduced the exact size and all thirty-nine instructions, including the saved floating-point register for the scaled bound extent, but copied the return value into the return register after the null-checked cache update rather than immediately after the multiplication before the pointer null checks.

## Spellings tried that did not help

- Multiplying `boundMax.y * GetScale()` without keeping `boundMax.y` in a local variable before the comparison (omitted the saved floating-point register).
- Storing `float maxY = boundMax.y;`, multiplying in place with `maxY *= GetScale();`, and returning `maxY` after the nested pointer checks.
- Inverting the bound-difference check into an early `return 1.0f;` before scaling.
- Adding an early `if (!process || !process->middleHigh50) return maxY;` before the cache store.
- Storing the product in a separate `const float result = maxY * GetScale();` local.

## Spelling that fixed it

none
