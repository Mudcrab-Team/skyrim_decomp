# 0xf97360 ControllerLeaff97360::~ControllerLeaff97360

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf97360 ControllerLeaff97360::~ControllerLeaff97360
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: instruction-order
- Best score: 62/62 aligned bytes after the fix
- Attempts: 2

## What differed
The first draft reloaded the reference from its owner before the final call. That added work and matched 58/62 aligned bytes.

## Spellings tried that did not help
- Reading the member separately for the count update and destruction call produced an extra reload.

## Spelling that fixed it
Keep the reference in a local variable across the atomic count update and the final call. The Windows comparator passed.
