# 0x155fed0 BSBatchRenderer::GetNextPassSlotInGroup

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x155fed0 BSBatchRenderer::GetNextPassSlotInGroup
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 100/100 bytes, local comparator pass
- Attempts: 1

## What differed

The slot search has two distinct terminal index values. Exhaustion leaves the index at the slot count and resets the caller's cursor. A hit preserves the found slot in the cursor and leaves the index one past the slot count.

## Spellings tried that did not help

None. The distinction between the two terminal values was visible before the first comparison.

## Spelling that fixed it

On a hit, write the current index to the cursor and set the loop index to the slot count. Let the normal loop increment run. After the loop, reset the cursor on exhaustion and test for the separate success value.
