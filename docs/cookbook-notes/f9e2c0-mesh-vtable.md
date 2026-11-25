# 0xf9e2c0 MeshDtorLeaff9e2c0::~MeshDtorLeaff9e2c0

<!-- tags: method/sibling, sibling/fo4, abi/virtual -->

- Function: 0xf9e2c0 MeshDtorLeaff9e2c0::~MeshDtorLeaff9e2c0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 106/106 aligned target bytes; candidate is 116 bytes
- Attempts: 1

## What differed
The candidate adds a derived vtable assignment that the target does not contain. All target bytes align, but the extra instruction makes the comparison fail.

## Spellings tried that did not help
- A derived virtual destructor with an inline list destructor emitted the additional store.

## Spelling that fixed it
None.
