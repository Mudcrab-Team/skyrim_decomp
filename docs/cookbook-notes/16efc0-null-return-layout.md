# 0x16efc0 ExtraDataList::Function16efc0

<!-- tags: wall/control-flow -->

- Function: 0x16efc0 ExtraDataList::Function16efc0
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: PC comparator PASS (all checks passed)
- Attempts: 2

## What differed

A nullable payload accessor selected the opposite branch orientation with the same operations.

## Spellings tried that did not help

Returning the payload inside a positive null check kept the different branch layout.

## Spelling that fixed it

Return null first for an absent payload, then return its carried pointer.
