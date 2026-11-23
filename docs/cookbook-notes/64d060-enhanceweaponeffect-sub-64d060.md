# 0x64d060 EnhanceWeaponEffect sub_64d060

- Function: 0x64d060 EnhanceWeaponEffect sub_64d060
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 61/69 bytes matching
- Attempts: 5

## What differed

The target joins the null-target and null-actor paths into one zero-pointer block and then tests that value before the process test; the candidate sends both null paths straight to the exit. Rule 40 describes the same symptom and its fix (an inline accessor with its own null test); not recorded as tried here. 0x64d290 is the sibling.

## Spellings tried that did not help

Nested if, ternary, helper function and && chains.

## Spelling that fixed it

none
