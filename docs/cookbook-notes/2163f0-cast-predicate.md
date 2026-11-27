# 0x2163f0 DynamicCastLeaf2163f0::Cast

<!-- tags: method/sibling, sibling/fo4, wall/control-flow -->

- Function: 0x2163f0 DynamicCastLeaf2163f0::Cast
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: branch-layout
- Best score: 87/87 aligned bytes
- Attempts: 2

## What differed
A local boolean moved its initial assignment ahead of the parent-chain loop and changed the branch layout.

## Spellings tried that did not help
- Assigning a local result in the loop matched 77/87 aligned bytes.

## Spelling that fixed it
A small predicate that returns directly from the loop gave the compiler the matching control flow when inlined.
