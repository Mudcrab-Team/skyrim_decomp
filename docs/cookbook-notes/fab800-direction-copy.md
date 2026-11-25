# 0xfab800 NiPSysDragFieldModifier::CopyMembers

<!-- tags: method/sibling, sibling/fo4, wall/layout -->

- Function: 0xfab800 NiPSysDragFieldModifier::CopyMembers
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: struct-layout
- Best score: 57/57 aligned bytes after the fix
- Attempts: 2

## What differed
The first spelling combined the first two direction components into one wider transfer, unlike the target's separate field transfers.

## Spellings tried that did not help
- Assigning the direction aggregate at once matched 45/57 aligned bytes.

## Spelling that fixed it
Assign each direction component independently. The Windows comparator passed.
