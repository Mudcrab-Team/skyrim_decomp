# 0x15212d0 BSShaderAccumulator::RenderFirstPersonView_End

<!-- tags: wall/register-schedule -->

- Function: 0x15212d0 BSShaderAccumulator::RenderFirstPersonView_End
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: register-allocation
- Best score: 135/135 aligned bytes
- Attempts: 5

## What differed

The pass-list teardown had the correct length and call order. The candidate saved different nonvolatile registers, so its unwind information also differed.

## Spellings tried that did not help

Treating the list head as independent renderer fields, or holding the renderer pointer across both the clear condition and the clear call, kept the register mismatch.

## Spelling that fixed it

Represent the first pass and the next node as the embedded head of the same list. Put the unlink-and-recycle loop on that head. Read batchRenderer in the clear condition and call Clear on its head, then read batchRenderer again for the final count reset.
