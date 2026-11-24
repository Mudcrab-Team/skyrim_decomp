# 0xf9d550 GravityCtorLeaff9d550::GravityCtorLeaff9d550

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf9d550 GravityCtorLeaff9d550::GravityCtorLeaff9d550
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 97/102 aligned bytes
- Attempts: 2

## What differed
The compiler schedules the final direction store after three later initialization stores, while the target completes the direction first.

## Spellings tried that did not help
- Initializer-list stores matched 97/102 aligned bytes.
- Moving the later assignments into the body lowered the score to 86/102.

## Spelling that fixed it
None.
