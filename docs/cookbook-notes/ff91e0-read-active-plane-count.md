# 0xff91e0 BSCompoundFrustum::GetActivePlaneState

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0xff91e0 BSCompoundFrustum::GetActivePlaneState
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 43/66 aligned matching bytes
- Attempts: 5

## What differed

The copy of the view mask and the loop that writes the remaining masks agree. Before that loop, the target compares the array size from memory and reuses that member directly when selecting the smaller count. The candidate loads the array size into another register. The extra load changes where the loop alignment begins.

## Spellings tried that did not help

A conditional expression, an explicit bound check and the standard minimum function all kept a separate load. Reversing the arguments to the standard minimum changed which member was read first and lowered the score. Every version retained the target function size.

## Spelling that fixed it

none
