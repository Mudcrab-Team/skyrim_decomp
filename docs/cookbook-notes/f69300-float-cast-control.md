# 0xf69300 FloatSyncLeaff69300::SynchronizePoseInterpolator

<!-- tags: method/sibling, sibling/fo4, wall/control-flow -->

- Function: 0xf69300 FloatSyncLeaff69300::SynchronizePoseInterpolator
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: branch-layout
- Best score: 100/100 aligned bytes
- Attempts: 2

## What differed
Combining the null check, type test and selection into one expression allowed the compiler to collapse branches that the target retains.

## Spellings tried that did not help
- The combined expression matched 71/100 aligned bytes.

## Spelling that fixed it
A separate inlined cast helper with its own null check produced the target branch layout.
