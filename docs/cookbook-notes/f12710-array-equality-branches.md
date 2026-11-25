# 0xf12710 IntegerExtraLeaff12710::IsEqual

<!-- tags: method/sibling, sibling/fo4, wall/control-flow -->

- Function: 0xf12710 IntegerExtraLeaff12710::IsEqual
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: branch-layout
- Best score: 87/87 aligned bytes after the fix
- Attempts: 2

## What differed
The first draft returned a null-pointer comparison directly and matched 59/87 aligned bytes. The target shares the failure and success paths across the checks.

## Spellings tried that did not help
- Returning the result of the null-pointer comparison directly produced a different branch layout.

## Spelling that fixed it
Check the populated-array case first and handle a mismatched null pointer in the alternate branch. The Windows comparator passed.
