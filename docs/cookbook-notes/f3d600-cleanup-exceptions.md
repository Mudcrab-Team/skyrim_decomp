# 0xf3d600 UnionBVLeaff3d600::~UnionBVLeaff3d600

<!-- tags: method/sibling, sibling/fo4, method/diagnostic -->

- Function: 0xf3d600 UnionBVLeaff3d600::~UnionBVLeaff3d600
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: other
- Best score: 71/71 aligned bytes and matching exception metadata after the fix
- Attempts: 2

## What differed
The initial draft matched the instructions but produced an additional exception-state mapping. The comparator rejected the exception metadata.

## Spellings tried that did not help
- Leaving the external child-removal helper potentially throwing retained the extra exception-state mapping.

## Spelling that fixed it
Declare the child-removal helper non-throwing, consistent with the observed exception metadata. The Windows comparator passed.
