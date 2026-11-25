# 0xfe0d60 BSPSysArrayEmitter::Functionfe0d60

<!-- tags: abi/exception, construct/allocation -->

- Function: 0xfe0d60 BSPSysArrayEmitter::Functionfe0d60
- Label: GUESS(low)
- Outcome: unsolved
- Cause: other
- Best score: normalized instruction distance 0.0; comparator FAIL
- Attempts: 3

## What differed

The factory code reached a normalized instruction distance of zero, but its exception metadata still failed the comparator.

## Spellings tried that did not help

Binding the shared language handler resolved the missing runtime reference. The exception-data mismatch remained. Instruction alignment alone did not close the unit.

## Spelling that fixed it

none
