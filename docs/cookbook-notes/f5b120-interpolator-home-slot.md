# 0xf5b120 InterpItemDtorLeaff5b120::~InterpItemDtorLeaff5b120

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf5b120 InterpItemDtorLeaff5b120::~InterpItemDtorLeaff5b120
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 82/92 aligned bytes
- Attempts: 1

## What differed
The candidate saves and restores a nonvolatile register in a different home slot, which also changes its unwind record.

## Spellings tried that did not help
- The permuter examined one candidate and did not improve the score.

## Spelling that fixed it
None.
