# 0x75ceb0 PlayerCharacter sub_75ceb0

- Function: 0x75ceb0 PlayerCharacter sub_75ceb0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 9/102 bytes matching at best, later worse
- Attempts: 3

## What differed

The prologue saves two registers where the target saves three, and the target has an un-rotated loop that reloads the array pointer each iteration; the candidate rotates it.

## Spellings tried that did not help

For with break, result test in the loop condition, while with an explicit increment.

## Spelling that fixed it

none
