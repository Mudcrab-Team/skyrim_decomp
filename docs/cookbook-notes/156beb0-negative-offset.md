# 0x156beb0 NiStringSearch156beb0::FindOneOf

<!-- tags: method/sibling, sibling/fo4, wall/control-flow -->

- Function: 0x156beb0 NiStringSearch156beb0::FindOneOf
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: branch-layout
- Best score: 59/59 aligned bytes after the fix
- Attempts: 2

## What differed
The initial conditional expression selected the failure value without the target's branch and matched 49/59 aligned bytes.

## Spellings tried that did not help
- A conditional expression for the negative-offset case produced a different control flow.

## Spelling that fixed it
Return the failure value in an explicit negative-offset branch, followed by the successful return. The Windows comparator passed.
