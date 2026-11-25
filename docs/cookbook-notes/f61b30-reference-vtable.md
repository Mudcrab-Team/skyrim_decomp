# 0xf61b30 RefDtorLeaff61b30::~RefDtorLeaff61b30

<!-- tags: method/sibling, sibling/fo4, abi/virtual -->

- Function: 0xf61b30 RefDtorLeaff61b30::~RefDtorLeaff61b30
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 99/99 aligned target bytes; candidate is 109 bytes
- Attempts: 3

## What differed
The derived virtual destructor adds a vtable assignment that is absent from the target. All target bytes align, but the extra instruction prevents a match.

## Spellings tried that did not help
- A derived virtual destructor with an inline reference-wrapper destructor emitted the additional store.
- Making the base destructor nonvirtual still emitted a vtable store.
- Explicit cleanup without a derived destructor matched 95/99 aligned bytes.

## Spelling that fixed it
None.
