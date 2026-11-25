# 0xf3bec0 SphereCtorLeaff3bec0::SphereCtorLeaff3bec0

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf3bec0 SphereCtorLeaff3bec0::SphereCtorLeaff3bec0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: instruction-order
- Best score: 85/85 aligned bytes after the fix
- Attempts: 2

## What differed
The first draft initialized the radius before loading the default center, while the target uses the opposite order. It matched 78/85 aligned bytes.

## Spellings tried that did not help
- Initializing the radius in the initializer list placed its store too early.

## Spelling that fixed it
Assign the default radius after the three default center components in the payload constructor. The Windows comparator passed.
