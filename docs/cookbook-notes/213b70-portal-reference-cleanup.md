# 0x213b70 BSPortal::~BSPortal

<!-- tags: construct/destructor, abi/virtual -->

- Function: 0x213b70 BSPortal::~BSPortal
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: vtable-or-virtual
- Best score: 110/110 aligned bytes
- Attempts: 5

## What differed

The scalar deleting destructor releases a shared-node reference before the base object count drops. The best candidate aligns every target byte but includes an extra derived virtual-table store before the release. Its function size still fails.

## Spellings tried that did not help

An explicit decrement in the outer destructor and a typed reference member with its own destructor both emitted that store. Holding the pointee during release recovered the shorter indirect call. The size-oriented recipe outlined more cleanup.

## Spelling that fixed it

None.
