# 0xf86cf0 ColorDataDtorLeaff86cf0::~ColorDataDtorLeaff86cf0

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf86cf0 ColorDataDtorLeaff86cf0::~ColorDataDtorLeaff86cf0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: 114/114 aligned bytes
- Attempts: 2

## What differed
Calling directly through the selected table entry emitted a different indirect-call shape.

## Spellings tried that did not help
- Calling through the indexed table expression matched 98/114 aligned bytes.

## Spelling that fixed it
Saving the selected function pointer in a local before calling it matched the target instruction and reference layout.
