# 0xf76750 BasisEqualLeaff76750::IsEqual

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf76750 BasisEqualLeaff76750::IsEqual
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: 56/56 aligned bytes after the fix
- Attempts: 2

## What differed
The first spelling used different registers for the final member comparison and matched 50/56 aligned bytes.

## Spellings tried that did not help
- Comparing the current object's count before the other object's count left a register-only difference.

## Spelling that fixed it
The permuter found the reversed comparison operands. A subsequent Windows comparator run passed.
