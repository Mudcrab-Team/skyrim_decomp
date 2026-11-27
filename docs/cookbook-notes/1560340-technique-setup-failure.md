# 0x1560340 BSBatchRenderer::SetupAndDrawPass

<!-- tags: wall/control-flow, wall/inlining, abi/exception -->

- Function: 0x1560340 BSBatchRenderer::SetupAndDrawPass
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: branch-layout
- Best score: 865/865 aligned bytes
- Attempts: 9

## What differed

The draw path expands all three immediate render helpers. Returning immediately on technique failure put the cache reset before the draw blocks in the candidate. The target places the reset after them.

## Spellings tried that did not help

Correcting the skin draw context recovered the nested draw sequence. That change alone did not recover the technique branch, even though the helper call counts agreed.

## Spelling that fixed it

Return success from the technique-setup helper, put material and geometry work in its success branch, and clear the active shader and technique in the failure branch. Rechecking the copy helper and property getter bindings closed the full comparison.
