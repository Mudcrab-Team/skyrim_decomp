# 0x18a8c0 ExtraAttachedArrows3D sub_18a8c0

- Function: 0x18a8c0 ExtraAttachedArrows3D sub_18a8c0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 98/105 bytes matching under fpfast
- Attempts: 4

## What differed

The target keeps a null-target merge block (clear a register, test, branch) that the optimiser folds away in every spelling; fpfast removed a parity branch. Rule 40 symptom.

## Spellings tried that did not help

Several spellings of the null merge; recipe left as o2-fpfast.

## Spelling that fixed it

none
