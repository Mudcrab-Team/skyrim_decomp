# 0xbb8550 BSIsActiveModifier sub_bb8550

- Function: 0xbb8550 BSIsActiveModifier sub_bb8550
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 35/51 bytes matching
- Attempts: 5

## What differed

Five inverted flag-byte stores: the target stores each result straight after its compare, the candidate hoists the next compare above the previous store. The loop was never unrolled by the compiler, so a loop spelling does not help.

## Spellings tried that did not help

uint8 and bool members, a pair struct, ==0 instead of !, a loop over the five tests.

## Spelling that fixed it

none
