# 0x155eaf0 BSBatchRenderer::~BSBatchRenderer

<!-- tags: abi/exception, construct/destructor -->

- Function: 0x155eaf0 BSBatchRenderer::~BSBatchRenderer
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: other
- Best score: 366/366 aligned bytes
- Attempts: 4

## What differed

The destructor reached the full body extent while exception comparison still rejected the number of instruction-to-state entries. An explicit call to destroy the array size member reproduced the normal cleanup but represented the wrong lifetime.

## Spellings tried that did not help

An unconditional clear of the contained renderer changed both nullable branches. Fixing those branches alone brought the body into alignment but left the exception map different.

## Spelling that fixed it

Clear the contained renderer inside its non-null branch. Give the size member its own destructor so the array cleanup runs through member destruction. The full comparator passed. The published hash has a different relocation layout.
