# 0x983760 BoolTimelineDtorLeaf983760::~BoolTimelineDtorLeaf983760

<!-- tags: method/sibling, sibling/fo4, abi/virtual -->

- Function: 0x983760 BoolTimelineDtorLeaf983760::~BoolTimelineDtorLeaf983760
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 99/99 aligned target bytes; candidate is 109 bytes
- Attempts: 1

## What differed
The candidate adds a derived vtable assignment that the target does not contain. All target bytes align, but the extra instruction makes the comparison fail.

## Spellings tried that did not help
- A derived virtual destructor with an inline reference-wrapper destructor emitted the additional store.

## Spelling that fixed it
None.
