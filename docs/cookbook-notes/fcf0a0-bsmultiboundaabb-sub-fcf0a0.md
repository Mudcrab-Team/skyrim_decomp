# 0xfcf0a0 BSMultiBoundAABB sub_fcf0a0

- Function: 0xfcf0a0 BSMultiBoundAABB sub_fcf0a0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 104/163 bytes matching, size 162 vs 163
- Attempts: 6

## What differed

A box tested against six planes under an active mask. The loop counter and the bit mask swap registers (the target keeps the counter in the return register), which flips the order in which the plane components are loaded. Recipe o2-fpfast. Counter/found-register swap as in rule 44.

## Spellings tried that did not help

A 64-bit index, shift-by-index instead of a moving mask, declaration order, expression order.

## Spelling that fixed it

none
