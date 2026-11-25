# 0xff5ad0 BSGeometryListCullingProcess::~BSGeometryListCullingProcess

<!-- tags: construct/destructor, abi/exception -->

- Function: 0xff5ad0 BSGeometryListCullingProcess::~BSGeometryListCullingProcess
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 3/269 aligned matching bytes
- Attempts: 3

## What differed

The deleting destructor clears per-group queues before destroying other members. The compiler emitted a different amount of inline cleanup.

## Spellings tried that did not help

A null range for the empty group array and changing the base destructor exception specification left the body too long.

## Spelling that fixed it

None.
