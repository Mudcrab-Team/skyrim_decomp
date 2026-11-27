# 0x1586dd0 BSParabolicCullingProcess::AppendNonAccum

<!-- tags: construct/loop, abi/exception -->

- Function: 0x1586dd0 BSParabolicCullingProcess::AppendNonAccum
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 230/377 aligned matching bytes
- Attempts: 2

## What differed

The primary hemisphere retains geometry in an array. The other can accumulate the same object under a recursive lock. The save set and the inlined lock path both differ.

## Spellings tried that did not help

Combining the retaining append with a scoped accumulator lock still produced a longer function.

## Spelling that fixed it

None.
