# 0xf3e2f0 UnionDtorLeaff3e2f0::~UnionDtorLeaff3e2f0

<!-- tags: method/sibling, sibling/fo4, method/diagnostic -->

- Function: 0xf3e2f0 UnionDtorLeaff3e2f0::~UnionDtorLeaff3e2f0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: other
- Best score: all instruction bytes aligned; exception metadata differs
- Attempts: 1

## What differed
The instructions align, but the comparator reports a different exception-handler maximum state. Matching instructions alone do not establish a pass.

## Spellings tried that did not help
- The initial destructor compiled to the target instruction shape but did not match the exception metadata.

## Spelling that fixed it
None.
