# 0x1561780 BSBatchRenderer::StopGroupingAlphas

<!-- tags: method/diagnostic, wall/register-schedule -->

- Function: 0x1561780 BSBatchRenderer::StopGroupingAlphas
- Label: GUESS(low)
- Outcome: unsolved
- Cause: other (published relocation layout)
- Best score: local full comparator PASS, 67 of 67 bytes covered. Published hash check returned no-target for the bound symbol.
- Attempts: 4

## What differed

The local comparator resolved the thread-local memory context. The published hash row uses an inferred relocation layout that differs from the object's layout, so the independent hash check could not compare them.

## Spellings tried that did not help

Saving and restoring the context explicitly produced a different register lifetime. Changing the count from signed to unsigned accounted for the subtraction and signed lower-bound check, but left that lifetime difference.

## Spelling that fixed it

A scoped object that saves the thread-local context in its constructor and restores it in its destructor reproduced the local target. The published hash layout remains unresolved.
