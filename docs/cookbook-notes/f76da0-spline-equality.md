# 0xf76da0 SplineDataLeaff76da0::IsEqual

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf76da0 SplineDataLeaff76da0::IsEqual
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: 67/67 aligned bytes after the fix
- Attempts: 2

## What differed
The initial combined condition used a different saved-register assignment and matched 31/67 aligned bytes.

## Spellings tried that did not help
- A single condition combining the base result and both member checks produced the wrong register assignment.

## Spelling that fixed it
The permuter split the base test from the member tests and reversed both comparison operands. A normal Windows comparison then passed.
