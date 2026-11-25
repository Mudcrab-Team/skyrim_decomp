# 0xfb95e0 NiPSysSpawnModifier::IsEqual

<!-- tags: construct/float, wall/register-schedule, abi/exception -->

- Function: 0xfb95e0 NiPSysSpawnModifier::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 96/136 aligned matching bytes under default floating point; final fast-floating-point draft 43/136 at distance 2.0
- Attempts: 4 counted comparisons; one bounded one-worker permutation search

## What differed

The default floating-point recipe inserted five unordered-value branches absent from the target. Cookbook rule 48 removed those branches using the existing fast-floating-point recipe and reduced alignment distance from 8.0 to 2.0. The resulting draft has the target extent, but frame layout and register assignment still differ. A score is diagnostic and none of these drafts is a byte match.

## Spellings tried that did not help

The initial base check followed by an equality conjunction, separate inequality early exits, and a single conjunction including the base check all retained distance 2.0 with fast floating point. The bounded one-worker permutation search tested 81 candidates without improvement. Three consecutive comparisons did not increase aligned matching-byte coverage, so the cheap search stopped.

## Spelling that fixed it

none
