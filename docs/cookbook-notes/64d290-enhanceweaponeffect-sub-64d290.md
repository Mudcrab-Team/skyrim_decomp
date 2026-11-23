# 0x64d290 EnhanceWeaponEffect sub_64d290

- Function: 0x64d290 EnhanceWeaponEffect sub_64d290
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 64/72 aligned bytes, size 68 vs 72
- Attempts: 6

## What differed

The target merges the null target and null actor into one zero-process join block that is tested; the candidate threads both null paths straight to the epilogue. Rule 40 describes this symptom; it was not recorded as tried. Same as 0x64d060.

## Spellings tried that did not help

An inline helper with early returns; a ternary with assignment.

## Spelling that fixed it

none
