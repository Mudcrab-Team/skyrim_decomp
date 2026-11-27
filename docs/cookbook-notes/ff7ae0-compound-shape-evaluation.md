# 0xff7ae0 BSCompoundFrustum::ProcessMultiBoundShape

<!-- tags: construct/loop, abi/exception -->

- Function: 0xff7ae0 BSCompoundFrustum::ProcessMultiBoundShape
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 120/274 aligned matching bytes
- Attempts: 2

## What differed

The compound shape evaluator reached the target size while its object lacked the required unwind coverage. The related portal evaluator at 0xff79c0 also retained control-flow differences.

## Spellings tried that did not help

An early return on an empty operator list and an enclosing positive-count condition changed branch placement. Neither recovered the complete object.

## Spelling that fixed it

None.
