# 0xfa1360 ExtraLeaffa1360::~ExtraLeaffa1360

<!-- tags: method/sibling, sibling/fo4, method/diagnostic -->

- Function: 0xfa1360 ExtraLeaffa1360::~ExtraLeaffa1360
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: other
- Best score: 51/51 aligned bytes after the fix
- Attempts: 2

## What differed
The initial comparison bound the member cleanup to the helper used in another task. Its instruction shape agreed, but the referenced target did not.

## Spellings tried that did not help
- Reusing the earlier task's cleanup binding matched 46/51 aligned bytes and failed the reference check.

## Spelling that fixed it
Removing the stale local binding let the verifier derive this function's cleanup target. The Windows comparator passed without a source change.
