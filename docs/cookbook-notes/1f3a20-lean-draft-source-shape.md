# 0x1f3a20 ActionInput::Function1f3a20

<!-- tags: method/diagnostic, wall/register-schedule -->

- Function: 0x1f3a20 ActionInput::Function1f3a20
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 53/53 aligned bytes; local comparator PASS
- Attempts: 2 verifier invocations, 2 counted; permutation candidates are separate

## What differed

Direct pointer-field stores and reference increments left one instruction-order difference.

## Spellings tried that did not help

A bounded permutation search of the direct body retained the same diagnostic distance. A single-worker search tried 49 candidates over 3 rounds; its diagnostic distance changed from 0.5 to 0.5, stopping at patience.

## Spelling that fixed it

Represent both pointer fields as owning reference members. Their inline constructors acquire ownership in field order. Their release behavior is corroborated by the separately observed base destructor. The containing constructor uses member initializers; its normal comparison passed.

This is first-host candidate evidence; a second host, independent review and integration remain required.
