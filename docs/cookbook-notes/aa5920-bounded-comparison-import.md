# 0xaa5920 hkString::Functionaa5920

<!-- tags: method/binding -->

- Function: 0xaa5920 hkString::Functionaa5920
- Label: GUESS(low)
- Outcome: fixed
- Cause: calling-convention
- Best score: PC comparator PASS (all checks passed)
- Attempts: 3

## What differed

The imported bounded operation was a three-argument string comparison. A copy declaration gave the call the wrong return contract even though its argument registers looked plausible.

## Spellings tried that did not help

A memory-copy declaration preserved the wrong return type and failed comparison.

## Spelling that fixed it

Declare the imported operation as a bounded comparison returning int and taking a size_t count.
