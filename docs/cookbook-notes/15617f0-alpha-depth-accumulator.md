# 0x15617f0 BSBatchRenderer::ComputeAlphaGroupDepth

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x15617f0 BSBatchRenderer::ComputeAlphaGroupDepth
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 82/175 aligned bytes
- Attempts: 4

## What differed

The projected depth is compared with the last alpha group. In the candidate the radius scale stays in its incoming register and the dot product uses another register. The target copies the scale on entry and accumulates the dot product in the register it frees.

## Spellings tried that did not help

Switching the first product to direction-first, multiplying the scale in place and comparing with the fast floating-point recipe left the best score unchanged. Computing a common fallback depth before comparing the last group moved the empty-pass branch and reduced the score.

## Spelling that fixed it

none
