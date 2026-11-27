# 0xf7c6d0 NiFloatsExtraDataController::IsEqual

<!-- tags: method/sibling, sibling/fo4, wall/control-flow -->

- Function: 0xf7c6d0 NiFloatsExtraDataController::IsEqual
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: branch-layout
- Best score: 59/59 aligned bytes after the fix
- Attempts: 2

## What differed
The first draft returned the field comparison directly after an early return. The compiler kept a different branch arrangement and matched 45/59 aligned bytes.

## Spellings tried that did not help
- Returning the comparison directly after the base check produced the wrong branch layout.

## Spelling that fixed it
Combine the base check and member comparison in a positive condition, returning true only when both succeed. The Windows comparator passed.
