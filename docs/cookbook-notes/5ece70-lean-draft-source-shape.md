# 0x5ece70 Unk5ece70::Function5ece70

<!-- tags: wall/constant -->

- Function: 0x5ece70 Unk5ece70::Function5ece70
- Label: GUESS(low)
- Outcome: fixed
- Cause: other
- Best score: 9/9 aligned bytes; local comparator PASS
- Attempts: 2 verifier invocations, 2 counted; permutation candidates are separate

## What differed

The initial shape classifier mistook a member store for a constant-return leaf.

## Spellings tried that did not help

The constant-return candidate had the wrong function extent.

## Spelling that fixed it

Write the observed member assignment with a void return. The corrected behavior passed the normal comparator.

This is first-host candidate evidence; a second host, independent review and integration remain required.
