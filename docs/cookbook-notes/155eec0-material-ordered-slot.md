# 0x155eec0 BSBatchRenderer::RegisterPassSorted

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0x155eec0 BSBatchRenderer::RegisterPassSorted
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 171/208 aligned bytes
- Attempts: 6

## What differed

The insertion walk stops at the first material key greater than or equal to the incoming key. The closest draft used the same link updates. The lifetime of the signed slot and the final occupancy-mask update still differed.

## Spellings tried that did not help

A pointer-to-link walk with a named copy of the slot gave the best result. Passing the slot by value into a group method changed the order of the material and slot loads. Computing the key at the caller did not bring the original register assignment back.

## Spelling that fixed it

none
