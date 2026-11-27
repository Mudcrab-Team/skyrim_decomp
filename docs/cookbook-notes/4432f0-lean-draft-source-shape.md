# 0x4432f0 ActorValueList::Function4432f0

<!-- tags: wall/control-flow, wall/layout -->

- Function: 0x4432f0 ActorValueList::Function4432f0
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 27/27 aligned bytes; local comparator PASS
- Attempts: 3 verifier invocations, 3 counted; permutation candidates are separate

## What differed

The bounds predicate had the correct extent but used a different inclusive comparison spelling.

## Spellings tried that did not help

Changing only singleton access did not improve the initial code mismatch.

## Spelling that fixed it

Use the inclusive bound of 163 for the 164-entry table. Keep the singleton accessor and observed table view.

This is first-host candidate evidence; a second host, independent review and integration remain required.
