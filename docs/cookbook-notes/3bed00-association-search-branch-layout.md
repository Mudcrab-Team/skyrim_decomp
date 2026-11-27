# 0x3bed00 TESNPC::HasAssociationType

<!-- tags: construct/loop, wall/control-flow, method/sibling, sibling/fo4 -->

- Function: 0x3bed00 TESNPC::HasAssociationType
- Label: SIBLING(fo4-private@1b765c70, author-permission); GUESS(low)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 63/66 aligned matching bytes, distance 2.5
- Attempts: 4

## What differed
A nullable relationship-array search found an association type through each non-null relationship. The compiled draft had the same size but placed the null-array return before the search, while the target retained a trailing return boundary. The permitted sibling method supplied the search behavior and naming lead; the target observations supplied the provisional offsets.

## Spellings tried that did not help
Reading the count into a local before initializing the result retained 63/66. Nesting the search under the non-null condition reduced the function to 63 bytes and scored 52/66. Moving the scan into a normal inline array helper returned to 63/66 with the original branch difference. No unresolved references were present.

## Spelling that fixed it
None. The early-return draft is retained as the best source. Work stopped after three consecutive comparisons without improvement. The remaining wall is branch placement, rather than an isolated register allocation difference.
