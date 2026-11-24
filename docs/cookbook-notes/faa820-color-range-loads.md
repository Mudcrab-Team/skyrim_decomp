# 0xfaa820 ColorSetLeaffaa820::SetColorData

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xfaa820 ColorSetLeaffaa820::SetColorData
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: instruction-order
- Best score: 114/114 aligned bytes
- Attempts: 2

## What differed
Combining the pointer and count checks let the compiler reorder loads around the count test.

## Spellings tried that did not help
- A combined condition and repeated member access matched 71/114 aligned bytes.

## Spelling that fixed it
Naming the count, stride and key pointer before testing the count produced the target load sequence.
