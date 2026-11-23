# 0x18b1c0 ExtraUniqueID sub_18b1c0

- Function: 0x18b1c0 ExtraUniqueID sub_18b1c0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: branch-layout
- Best score: size 23 vs 37
- Attempts: 2

## What differed

A 16-bit and 32-bit compare: the target keeps the second result through a conditional move and a preset zero byte; the candidate emits set-on-condition. Rule 43.

## Spellings tried that did not help

An explicit result flag.

## Spelling that fixed it

none
