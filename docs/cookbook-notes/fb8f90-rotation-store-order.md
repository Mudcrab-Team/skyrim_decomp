# 0xfb8f90 RotationCtorLeaffb8f90::RotationCtorLeaffb8f90

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xfb8f90 RotationCtorLeaffb8f90::RotationCtorLeaffb8f90
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 79/88 aligned bytes
- Attempts: 2

## What differed
The candidate loads the flag constant into a register and schedules the final direction store after the flag write. The target uses a direct flag store after the direction stores.

## Spellings tried that did not help
- Initializing the flag in either the initializer list or constructor body produced the same result.

## Spelling that fixed it
None.
