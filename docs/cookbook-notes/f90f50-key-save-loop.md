# 0xf90f50 KeySavef90f50::SaveToStream

<!-- tags: method/sibling, sibling/fo4, construct/loop -->

- Function: 0xf90f50 KeySavef90f50::SaveToStream
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: loop-shape
- Best score: 69/69 aligned bytes after the fix
- Attempts: 3

## What differed
The first loop used a different counter width and saved-register assignment, matching 26/69 aligned bytes. Widening the countdown improved the score to 30/69 but retained the register difference.

## Spellings tried that did not help
- A decrementing 32-bit loop changed the counter width.
- A decrementing 64-bit loop retained a different register allocation; the permuter did not improve it.

## Spelling that fixed it
Use an indexed loop over the elements. The Windows comparator passed.
