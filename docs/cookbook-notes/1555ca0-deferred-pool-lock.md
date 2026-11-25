# 0x1555ca0 DrainRenderPassDeferredFreeQueue

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x1555ca0 DrainRenderPassDeferredFreeQueue
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 67/363 aligned bytes
- Attempts: 2

## What differed

The queue node and its pass survive acquisition of the selected pool lock. The candidate has a different retry loop and register assignments across the yield calls. This also changes addressing when the pass is appended to the free list.

## Spellings tried that did not help

The first draft kept a pool reference across lock acquisition. Keeping the numeric pool index instead and spelling out the retry counter increased the differences. The threshold and the first yield still need to be checked together.

## Spelling that fixed it

none
