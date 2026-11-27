# 0xf5c9a0 BlendIndexLeaff5c9a0::GetHighestWeightedIndex

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf5c9a0 BlendIndexLeaff5c9a0::GetHighestWeightedIndex
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: instruction-order
- Best score: 72/72 aligned bytes after the fix
- Attempts: 3

## What differed
The initial draft omitted the target's explicit no-result branch and matched 62/72 aligned bytes. Adding the branch improved it to 70/72, but the initializations still appeared in a different order.

## Spellings tried that did not help
- Returning the result directly omitted the no-result branch.
- Adding the branch without changing local declaration order left an instruction-order difference.

## Spelling that fixed it
Declare the index, best weight and result in the order used by the target, retaining the explicit no-result branch. The Windows comparator passed.
