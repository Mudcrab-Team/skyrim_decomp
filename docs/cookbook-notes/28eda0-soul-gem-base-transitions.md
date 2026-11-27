# 0x28eda0 TESSoulGem::~TESSoulGem

<!-- tags: construct/destructor, abi/virtual, sibling/fo4, method/sibling -->

- Function: 0x28eda0 TESSoulGem::~TESSoulGem
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: full native comparator PASS
- Attempts: 3

## What differed
The destructor needs the primary table and nine secondary component tables before clearing the data and calling the misc-item base destructor.

## Spellings tried that did not help
A single opaque primary base cannot represent the observed secondary table transitions.

## Spelling that fixed it
Use the evidenced multiple-base extents and the permitted destructor body. Keep the misc-item destructor out of line; let the derived destructor generate its component-table stores.
