# 0x4430e0 ActorValueList::Function4430e0

<!-- tags: wall/control-flow, wall/layout -->

- Function: 0x4430e0 ActorValueList::Function4430e0
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 36/36 aligned bytes; local comparator PASS
- Attempts: 4 verifier invocations, 4 counted; permutation candidates are separate

## What differed

The out-of-range predicate had the correct extent but a different comparison encoding.

## Spellings tried that did not help

Changing only singleton access did not improve the initial code mismatch.

## Spelling that fixed it

Use an index above 163 as the rejection predicate. The corresponding table lookup passed; the expanded header was then rechecked.

This is first-host candidate evidence; a second host, independent review and integration remain required.
