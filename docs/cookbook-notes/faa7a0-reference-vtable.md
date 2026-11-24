# 0xfaa7a0 RefDtorLeaffaa7a0::~RefDtorLeaffaa7a0

<!-- tags: method/sibling, sibling/fo4, abi/virtual -->

- Function: 0xfaa7a0 RefDtorLeaffaa7a0::~RefDtorLeaffaa7a0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 99/99 aligned target bytes; candidate is 109 bytes
- Attempts: 1

## What differed
The derived virtual destructor adds a vtable assignment that is absent from the target. All target bytes align, but the extra instruction prevents a match.

## Spellings tried that did not help
- A derived virtual destructor with an inline reference-wrapper destructor emitted the additional store.

## Spelling that fixed it
None.
