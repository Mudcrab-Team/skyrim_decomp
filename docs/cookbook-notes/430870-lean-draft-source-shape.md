# 0x430870 Unk430870::Function430870

<!-- tags: method/diagnostic, wall/control-flow, wall/layout -->

- Function: 0x430870 Unk430870::Function430870
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 17/17 aligned bytes; local comparator PASS
- Attempts: 2 verifier invocations, 2 counted; permutation candidates are separate

## What differed

The equal-value early return produced a different branch layout with the same extent.

## Spellings tried that did not help

The first equal-value early-return form remained a code mismatch. A single-worker search tried 10 candidates over 1 rounds; its diagnostic distance changed from 1.5 to 0.0, stopping at distance-0.

## Spelling that fixed it

Put the unequal-value case first, store and return true there, then return false after the conditional. A bounded search found the form; the normal comparison passed.

This is first-host candidate evidence; a second host, independent review and integration remain required.
