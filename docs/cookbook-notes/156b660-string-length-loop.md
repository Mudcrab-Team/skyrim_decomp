# 0x156b660 NiString::NiString

<!-- tags: method/sibling, sibling/fo4, construct/loop -->

- Function: 0x156b660 NiString::NiString
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: loop-shape
- Best score: 54/54 aligned bytes after the fix
- Attempts: 2

## What differed
The first draft used a pre-checked loop to count the allocated string, producing an extra empty-string path.

## Spellings tried that did not help
- Initializing the count to zero and checking before incrementing matched 45/54 aligned bytes.

## Spelling that fixed it
Initialize the count to its maximum value and increment before each character test. The Windows comparator passed.
