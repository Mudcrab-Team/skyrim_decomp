# 0x2269a0 InterpItemDtorLeaf2269a0::~InterpItemDtorLeaf2269a0

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0x2269a0 InterpItemDtorLeaf2269a0::~InterpItemDtorLeaf2269a0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 82/92 aligned bytes
- Attempts: 2

## What differed
Caching each referenced pointer removed redundant reloads. The remaining save and restore use a different home slot, with a corresponding unwind difference.

## Spellings tried that did not help
- Accessing the reference through its field on each use matched 63/92 aligned bytes.
- Caching the reference raised the score to 82/92. The permuter had one candidate and did not improve it.

## Spelling that fixed it
None.
