# 0x51c5b0 BGSQueuedObjectInitialLoad::CheckPreconditions

<!-- tags: construct/bitfield, construct/loop, method/diagnostic, method/sibling, sibling/fo4, wall/control-flow, wall/inlining -->

- Function: 0x51c5b0 BGSQueuedObjectInitialLoad::CheckPreconditions
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 62/71 aligned matching bytes; distance 6; candidate extent 74, target extent 71
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The parent readiness check and four-child traversal retain branch layout and extra-instruction differences. The best comparison reports a function-size mismatch. Its alignment classifies control-flow and prologue differences as well as two extra instructions and one missing instruction; this is not only register selection. Skipping the state predicate for absent children improved the score but retained the size mismatch. The body is adapted from the permitted sibling's child-state walk with target-specific null handling. The sibling is a shape and name lead, not target evidence.

## Spellings tried that did not help

- Caching the children pointer in the caller: 43/71 aligned matching bytes, distance 10.
- Calling a child lookup helper and testing the two state bits separately: unchanged at 43/71, distance 10.
- Moving the traversal into an inline readiness helper with a combined mask improved the measured score to 58/71 and distance 7, but still failed at extent 74 versus 71.
- Caching the child array and returning early when it is absent inside the helper regressed to 19/71 and distance 15.
- Testing the child-array member directly for an early absent-children return reached 54/71, below the best result.

- Skipping absent children inside the traversal, rather than returning immediately, improved the best to 62/71 and distance 6; the candidate extent remained 74 versus 71.

## Spelling that fixed it

none. The best failed draft is preserved privately. The six-comparison cap was reached. No byte match or semantic equivalence is claimed; structural differences remain, so a register-only permutation diagnosis is unsupported.
