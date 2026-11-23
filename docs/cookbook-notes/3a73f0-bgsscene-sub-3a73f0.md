# 0x3a73f0 BGSScene sub_3a73f0

- Function: 0x3a73f0 BGSScene sub_3a73f0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 129/127 bytes, distance 4.25
- Attempts: 6

## What differed

Only register allocation differs: the target keeps the bit index in one register and this and the size in callee-saved registers; the candidate moves the bit into another register.

## Spellings tried that did not help

Rule 16 by-value bit helper, bit-test as a value, bit-test as a branch (closest), the index search as an inline member, uint8 bit, swapped loop condition.

## Spelling that fixed it

none
