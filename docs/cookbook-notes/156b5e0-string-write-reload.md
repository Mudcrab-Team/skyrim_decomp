# 0x156b5e0 CharStringCtorLeaf156b5e0::CharStringCtorLeaf156b5e0

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0x156b5e0 CharStringCtorLeaf156b5e0::CharStringCtorLeaf156b5e0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: 107/107 aligned bytes
- Attempts: 2

## What differed
Writing the first character through the member pointer caused the compiler to reload that pointer before writing the terminator.

## Spellings tried that did not help
- Using the member pointer for both writes matched 102/107 aligned bytes.

## Spelling that fixed it
Holding the allocated character pointer in a local for the two writes eliminated the redundant reload.
