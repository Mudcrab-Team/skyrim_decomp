# 0xf02f60 NiBillboardNode sub_f02f60

- Function: 0xf02f60 NiBillboardNode sub_f02f60
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: float-codegen
- Best score: size 286 to 295 vs 300
- Attempts: 6

## What differed

The target interleaves the three row sums of a rotation, then scales and adds, with two vector spills; the candidate schedules per component. Rule 45 family.

## Spellings tried that did not help

Strict and o2-fpfast recipes, temporaries, inline forms.

## Spelling that fixed it

none
