# 0xf88530 StringPaletteLeaff88530::IsEqual

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf88530 StringPaletteLeaff88530::IsEqual
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: operand-order
- Best score: 91/91 aligned bytes
- Attempts: 2

## What differed
Comparing the two stored fields in the initial operand order caused the compiler to load from the opposite object.

## Spellings tried that did not help
- Comparing this object's fields first matched 81/91 aligned bytes.

## Spelling that fixed it
Comparing the other object's fields first produced the target operand order.
