# 0xf112b0 FloatsCopyLeaff112b0::CopyMembers

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf112b0 FloatsCopyLeaff112b0::CopyMembers
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 128-byte candidate for a 123-byte target; distance 11.5
- Attempts: 2

## What differed
The recovered float-array copy adds one instruction and changes the allocation/copy register schedule. The function does not pass.

## Spellings tried that did not help
- The recovered explicit count store and element-copy loop produce the size difference. Retrying without exception handling leaves the distance unchanged.

## Spelling that fixed it
None.
