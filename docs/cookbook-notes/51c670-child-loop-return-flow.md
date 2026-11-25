# 0x51c670 BGSQueuedTerrainInitialLoad::CheckPreconditions

<!-- tags: construct/loop, construct/bitfield, wall/register-schedule, wall/flag-fold -->

- Function: 0x51c670 BGSQueuedTerrainInitialLoad::CheckPreconditions
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 15/71 aligned matching bytes; candidate size 73/71
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The parent-state rejection and child-loop failure share a return, but the compiler places the shared rejection after the loop. The target places that rejection before the loop and uses a different loop-counter register. The candidate remains two bytes longer. The state-bit helper preserves the required shift-based tests; rule 16 explains that portion only.

## Spellings tried that did not help
The interrupted draft rejected the opposite child-state condition; correcting it restored the observed behavior but did not improve the byte score. Early return and a nested accepted-parent block both scored 15/71. Moving child-array access into an ordinary inline GetChild accessor also scored 15/71. The bounded PC permuter used one job, batches of eight and a 60-second budget; its pool exhausted at distance 10.5 without improvement after 225 candidates. Three consecutive unchanged comparison scores reached the assigned stop rule.

## Spelling that fixed it
none
