# 0x155fc90 BSBatchRenderer::GetVertexShaderForTechnique

<!-- tags: wall/register-schedule, construct/loop -->

- Function: 0x155fc90 BSBatchRenderer::GetVertexShaderForTechnique
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 91/155 aligned bytes
- Attempts: 4

## What differed

The caller starts the group lookup with an empty result. On a hit it carries the group index into the slot search. The candidate delays the zero or puts it directly in the argument register. Both drafts also place the successful return before the fallback call.

## Spellings tried that did not help

Returning the group directly from the lookup and writing it through a reference produced different register assignments. Saving the input key before starting the lookup improved the output-reference version. Saving the fallback result before returning left that score unchanged.

## Spelling that fixed it

none
