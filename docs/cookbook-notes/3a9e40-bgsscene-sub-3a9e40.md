# 0x3a9e40 BGSScene sub_3a9e40

- Function: 0x3a9e40 BGSScene sub_3a9e40
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 55/60 bytes matching
- Attempts: 4

## What differed

The target zeroes a register before comparing the stored flag byte with it; the candidate compares against an immediate.

## Spellings tried that did not help

!x, == false, a zero variable, a char member.

## Spelling that fixed it

none
