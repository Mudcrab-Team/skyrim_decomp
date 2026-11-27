# 0xf8a580 RefDtorLeaff8a580::~RefDtorLeaff8a580

<!-- tags: method/sibling, sibling/fo4, abi/virtual -->

- Function: 0xf8a580 RefDtorLeaff8a580::~RefDtorLeaff8a580
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 99/99 aligned target bytes; candidate is 109 bytes
- Attempts: 1

## What differed
The candidate adds a derived vtable assignment absent from the target. All target bytes align, but the extra instruction prevents a match.

## Spellings tried that did not help
- A derived virtual destructor with an inline reference-wrapper destructor emitted the additional store.

## Spelling that fixed it
None.
