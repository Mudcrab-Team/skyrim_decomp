# 0x156b590 StringCtorLeaf156b590::StringCtorLeaf156b590

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0x156b590 StringCtorLeaf156b590::StringCtorLeaf156b590
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 64/70 aligned bytes
- Attempts: 2

## What differed
The target chooses the clamp result into a different register before extending it for allocation.

## Spellings tried that did not help
- A conditional expression and an explicit assignment produced the same alternate register choice.
- The permuter scored 481 candidates without improving the baseline.

## Spelling that fixed it
None.
