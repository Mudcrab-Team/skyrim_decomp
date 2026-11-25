# 0x155ec70 BSBatchRenderer::ClearAllRenderPasses

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x155ec70 BSBatchRenderer::ClearAllRenderPasses
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 66/383 aligned bytes
- Attempts: 3

## What differed

The first occupied entry is sought separately from later entries. A straightforward loop over the table also clears the correct five pass slots but produces a different search and clear sequence.

## Spellings tried that did not help

Searching for the first occupied entry before the main loop improved alignment. Replacing the five-slot counted clear with individual assignments left the best aligned-byte score unchanged. The entry iterator and node recycling still differ.

## Spelling that fixed it

none
