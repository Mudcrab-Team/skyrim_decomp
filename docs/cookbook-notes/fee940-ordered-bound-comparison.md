# 0xfee940 BSCullingProcess::TestBaseVisibility3

<!-- tags: construct/float, wall/control-flow -->

- Function: 0xfee940 BSCullingProcess::TestBaseVisibility3
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: 198/198 aligned matching bytes
- Attempts: 4

## What differed

Equality and unordered comparisons change which return path classifies the sphere.

## Spellings tried that did not help

An ordered less-than-or-equal test failed. Reordering the nested conditional still changed the branch layout.

## Spelling that fixed it

Test the negation of the greater-than comparison first, then classify the other two cases.
