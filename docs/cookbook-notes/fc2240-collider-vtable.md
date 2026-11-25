# 0xfc2240 ColliderDtorLeaffc2240::~ColliderDtorLeaffc2240

<!-- tags: method/sibling, sibling/fo4, abi/virtual -->

- Function: 0xfc2240 ColliderDtorLeaffc2240::~ColliderDtorLeaffc2240
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 107/107 aligned target bytes; candidate is 117 bytes
- Attempts: 2

## What differed
The candidate adds a derived vtable assignment absent from the target. All target bytes align after binding the base vtable, but the extra instruction prevents a match.

## Spellings tried that did not help
- A derived virtual destructor with an inline reference-wrapper destructor emitted the additional store.
- Correcting the private base-vtable binding raised the aligned score but retained the extra store.

## Spelling that fixed it
None.
