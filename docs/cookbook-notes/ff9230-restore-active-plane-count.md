# 0xff9230 BSCompoundFrustum::SetActivePlaneState

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0xff9230 BSCompoundFrustum::SetActivePlaneState
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 48/67 aligned matching bytes
- Attempts: 8

## What differed

The view receives the first mask and the remaining masks advance with the plane array. The difference starts when the function clamps the number of planes. The target compares the array size in memory and selects it directly from there. The best candidate holds that size in a register.

## Spellings tried that did not help

The best result used the standard minimum with array size first and the free-plane index second. An explicit bound check, reversing the minimum arguments, forming the end pointer directly and extracting a count accessor each left a different instruction sequence before the loop.

## Spelling that fixed it

none
