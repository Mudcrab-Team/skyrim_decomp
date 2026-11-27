# 0xf9bc50 NiPSysEmitterCtlr::TargetIsRequiredType

<!-- tags: construct/loop, wall/control-flow, wall/register-schedule -->

- Function: 0xf9bc50 NiPSysEmitterCtlr::TargetIsRequiredType
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 79/140 aligned bytes
- Attempts: 5

## What differed
The best candidate has the target function size and no missing or extra reference behavior in the diagnostic tally. The remaining classes include branch layout, argument setup, instruction order, and register renaming. A size match is not a byte match.

## Spellings tried that did not help
A loop advancing the modifier-list node only after a failed name comparison scored 60/140. Returning a pointer to the node's value did not change that score. Removing the initial RTTI null guard in isolation scored 57/140. Advancing the node as part of obtaining its value improved to 79/140. A one-worker permutation searched 81 candidates and retained the initial distance of 5.6. The final compare only refreshes the source record after naming cleanup; it does not claim a new fix.

## Spelling that fixed it
none
