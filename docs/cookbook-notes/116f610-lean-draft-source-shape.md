# 0x116f610 Unk116f610::Function116f610

<!-- tags: method/diagnostic -->

- Function: 0x116f610 Unk116f610::Function116f610
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 22/22 aligned bytes; local comparator PASS
- Attempts: 2 verifier invocations, 2 counted; permutation candidates are separate

## What differed

Selecting between two loaded values produced a different function extent.

## Spellings tried that did not help

The direct conditional value expression did not close the comparison.

## Spelling that fixed it

Select a pointer to the linked value or local value, then load through that selected pointer once.

This is first-host candidate evidence; a second host, independent review and integration remain required.
