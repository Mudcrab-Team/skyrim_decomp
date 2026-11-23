# 0x3cc660 TESActorBase sub_3cc660

- Function: 0x3cc660 TESActorBase sub_3cc660
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 80/102 bytes matching
- Attempts: 6

## What differed

A find-first loop with a conditional move: the target increments the index after copying it, the candidate hoists the address computation or strength-reduces to a pointer. Rule 44.

## Spellings tried that did not help

Several loop shapes (see rule 44).

## Spelling that fixed it

none
