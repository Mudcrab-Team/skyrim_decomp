# 0x15618b0 BSBatchRenderer::RenderAlphaSortedPasses

<!-- tags: construct/loop, construct/float, wall/control-flow -->

- Function: 0x15618b0 BSBatchRenderer::RenderAlphaSortedPasses
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 295/648 aligned bytes
- Attempts: 3

## What differed

Rendering interleaves depth-sorted groups with the current pass. A geometry cursor and a progress flag control whether another iteration is possible. The candidate spills different values and places the transitions after an ineligible pass differently.

## Spellings tried that did not help

A loop that clears its geometry cursor after an ineligible pass measured lower than one with an explicit termination check there. The second draft still differed in its frame, depth comparisons and loop branches.

## Spelling that fixed it

none
