# 0x3c7460 TESNPC sub_3c7460

- Function: 0x3c7460 TESNPC sub_3c7460
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: instruction-order
- Best score: size 45 vs 50
- Attempts: 6

## What differed

The ActorValueOwner subobject override. Same instruction set; the target loads the constant argument before the float-to-byte convert and recomputes the index; the candidate converts first. Rule 45.

## Spellings tried that did not help

The result line records no specific spellings.

## Spelling that fixed it

none
