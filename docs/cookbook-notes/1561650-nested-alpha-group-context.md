# 0x1561650 BSBatchRenderer::StartGroupingAlphas

<!-- tags: abi/exception, construct/float, wall/register-schedule -->

- Function: 0x1561650 BSBatchRenderer::StartGroupingAlphas
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 162/297 aligned bytes
- Attempts: 3

## What differed

The group is reserved before its old passes are cleared. Clearing temporarily enters the same memory context again. The candidate uses different saved registers for the group, camera and context and addresses the nested context differently.

## Spellings tried that did not help

Keeping a possibly-null result separate from the reserved group improved the comparison. Moving the reset into a helper taking the group by reference left that improved score unchanged.

## Spelling that fixed it

none
