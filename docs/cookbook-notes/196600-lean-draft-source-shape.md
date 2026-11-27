# 0x196600 Unk196600::Function196600

<!-- tags: abi/calling-convention -->

- Function: 0x196600 Unk196600::Function196600
- Label: GUESS(low)
- Outcome: fixed
- Cause: calling-convention
- Best score: 11/11 aligned bytes; local comparator PASS
- Attempts: 2 verifier invocations, 2 counted; permutation candidates are separate

## What differed

The static declaration placed the explicit pointer in the first argument position. The observed member-call ABI used the second argument position.

## Spellings tried that did not help

Keeping the same body under the static declaration failed.

## Spelling that fixed it

Declare an instance method with the explicit pointer parameter. The method does not need to read its implicit object.

This is first-host candidate evidence; a second host, independent review and integration remain required.
