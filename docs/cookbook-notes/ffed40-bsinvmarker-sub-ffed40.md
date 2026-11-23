# 0xffed40 BSInvMarker sub_ffed40

- Function: 0xffed40 BSInvMarker sub_ffed40
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 10 of 18 instructions exact, 68/68 size
- Attempts: 5

## What differed

After the base copy call the target loads all four values (the float first) before storing any; the candidate keeps the values in integer registers and loads them in another order. Rule 42 (two operands loaded in the other order) with a float involved.

## Spellings tried that did not help

Temporaries in both orders; the o2-fpfast recipe.

## Spelling that fixed it

none
