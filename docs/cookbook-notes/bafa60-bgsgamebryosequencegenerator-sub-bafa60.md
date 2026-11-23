# 0xbafa60 BGSGameBryoSequenceGenerator sub_bafa60

- Function: 0xbafa60 BGSGameBryoSequenceGenerator sub_bafa60
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 50/58 bytes matching
- Attempts: 15

## What differed

The candidate copies 1.0 to the result register before the mode test and re-zeroes the zero return; the target returns the register holding zero. Shared const zero locals turn the clamp into a minimum instruction. Rule 45.

## Spellings tried that did not help

Shared const zero locals and other result placements.

## Spelling that fixed it

none
