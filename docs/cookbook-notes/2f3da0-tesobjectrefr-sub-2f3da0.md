# 0x2f3da0 TESObjectREFR sub_2f3da0

- Function: 0x2f3da0 TESObjectREFR sub_2f3da0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: constant-folding
- Best score: 54/82 matching bytes, size 73 vs 82
- Attempts: 3

## What differed

The target keeps constant true in a callee-saved register and ands, selects with a conditional move against zero and returns from that register; the candidate folds it into immediates. Rule 43.

## Spellings tried that did not help

bool and uint8 result variables, a ternary select.

## Spelling that fixed it

none
