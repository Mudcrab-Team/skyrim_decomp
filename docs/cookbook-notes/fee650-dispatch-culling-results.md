# 0xfee650 BSCullingProcess::SubmitCullResults

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0xfee650 BSCullingProcess::SubmitCullResults
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 145/370 aligned matching bytes
- Attempts: 1

## What differed

The collector treats the first object separately, then filters the remaining objects in both the deferred and synchronous paths. The deferred path and its cleanup remain shorter in the candidate.

## Spellings tried that did not help

A scoped job batch followed by a finish call preserved the two execution paths but did not recover the target size.

## Spelling that fixed it

None.
