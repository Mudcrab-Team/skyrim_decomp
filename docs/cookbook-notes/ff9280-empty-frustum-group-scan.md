# 0xff9280 BSCompoundFrustum::RemoveEmptyGroups

<!-- tags: construct/loop, construct/switch, wall/register-schedule -->

- Function: 0xff9280 BSCompoundFrustum::RemoveEmptyGroups
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 199/205 aligned matching bytes
- Attempts: 5 comparisons

## What differed

The candidate compacts the same operator fields and has the expected length. The two tests for consecutive operator types use addition of a negative constant where the target subtracts a positive one.

## Spellings tried that did not help

Pairing equality tests, using inclusive enum ranges and switching on the operator type all retained the same arithmetic difference.

## Spelling that fixed it

none
