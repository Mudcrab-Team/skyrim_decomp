# 0x155fd40 BSBatchRenderer::GetNextActivePassIndex

<!-- tags: construct/loop, abi/exception -->

- Function: 0x155fd40 BSBatchRenderer::GetNextActivePassIndex
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 148/388 aligned bytes
- Attempts: 3

## What differed

The cursor search can recycle a node under a scoped lock and then look up its group. The candidate differs in its saved-register set and in the control flow around the lower range limit and pool return.

## Spellings tried that did not help

Moving the initial group result ahead of the range check reduced the score. Separating the first assignment to the output technique from the loop test did not recover the original score.

## Spelling that fixed it

none
