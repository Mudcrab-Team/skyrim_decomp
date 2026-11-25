# 0x155efa0 BSBatchRenderer::RegisterPass

<!-- tags: wall/register-schedule, construct/bitfield -->

- Function: 0x155efa0 BSBatchRenderer::RegisterPass
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: 170/170 aligned bytes
- Attempts: 5

## What differed

Both output locals start at zero. The array selection, signed slot index and bit-mask update depend on them. The first draft reloaded the slot for the mask and the stores to the two output locals were reversed.

## Spellings tried that did not help

A named copy of the slot alone did not match. Reordering just the declarations also left part of the setup different.

## Spelling that fixed it

Select the pass group before passing the slot by value to its insertion helper. Declare the group index first and initialize the slot first. The full comparator passed with the signed shift expression. The published hash has a different relocation layout.
