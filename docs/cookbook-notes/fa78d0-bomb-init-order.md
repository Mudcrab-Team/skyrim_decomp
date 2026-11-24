# 0xfa78d0 BombCtorLeaffa78d0::BombCtorLeaffa78d0

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xfa78d0 BombCtorLeaffa78d0::BombCtorLeaffa78d0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 81/86 aligned bytes
- Attempts: 2

## What differed
The best draft initializes the same fields but the compiler places the last direction store after two later zero stores. The target writes that direction component first.

## Spellings tried that did not help
- Initializing the later fields in the initializer list matched 75/86 aligned bytes.
- Moving those initializations into the body improved the score to 81/86 but left one ordering difference.
- The permuter could not find the constructor body when it had an initializer list, so it scored no candidates.

## Spelling that fixed it
None.
