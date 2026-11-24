# 0xf5c300 ArrayOwnerDtorLeaff5c300::~ArrayOwnerDtorLeaff5c300

<!-- tags: method/sibling, sibling/fo4, method/diagnostic -->

- Function: 0xf5c300 ArrayOwnerDtorLeaff5c300::~ArrayOwnerDtorLeaff5c300
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: other
- Best score: all instruction bytes aligned; exception metadata differs
- Attempts: 2

## What differed
The instructions align, but the comparator reports a different exception-handler maximum state. Matching instructions alone do not establish a pass.

## Spellings tried that did not help
- The initial destructor compiled to the target instruction shape but did not match the exception metadata.
- Changing a cleanup declaration's exception specification did not remove the metadata mismatch.

## Spelling that fixed it
None.
