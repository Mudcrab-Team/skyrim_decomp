# 0x1587230 BSParabolicCullingProcess::dtor

<!-- tags: construct/destructor, abi/exception -->

- Function: 0x1587230 BSParabolicCullingProcess::dtor
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 143/153 aligned matching bytes
- Attempts: 3

## What differed

The scalar deleting destructor has the expected body length. Its saved nonvolatile register occupies another home slot.

## Spellings tried that did not help

Loading the reference member into a local before the decrement and binding the scalar deleting destructor explicitly did not recover the target unwind record.

## Spelling that fixed it

None.
