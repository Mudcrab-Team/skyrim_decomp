# 0xf7dfa0 KeyManagerLeaff7dfa0::~KeyManagerLeaff7dfa0

<!-- tags: method/sibling, sibling/fo4, abi/virtual -->

- Function: 0xf7dfa0 KeyManagerLeaff7dfa0::~KeyManagerLeaff7dfa0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 64/64 aligned target bytes, candidate size 74/64 bytes
- Attempts: 1

## What differed
The candidate adds a derived virtual-table assignment before the two cleanup calls. The target does not have that assignment, and the candidate is ten bytes longer.

## Spellings tried that did not help
- A derived class with a virtual base destructor and an owned member produced the additional assignment.

## Spelling that fixed it
None.
