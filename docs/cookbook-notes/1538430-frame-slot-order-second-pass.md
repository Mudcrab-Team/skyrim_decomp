# 0x1538430 DrawWorld_RenderShadowCasters

<!-- tags: wall/register-schedule, method/diagnostic -->

- Function: 0x1538430 DrawWorld_RenderShadowCasters
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: struct-layout
- Best score: 555/604 aligned bytes
- Attempts: 5

## What differed

Same residue as the first pass: only three frame slots differ. The target puts the job-submit scope in the lowest of the incoming home slots, the
loop index next, and the saved memory context in the highest. The draft puts the scope highest and the index lowest, whatever the source order.

## Spellings tried that did not help

- The caster walk as its own non-static function that the compiler folds into the caller, instead of an inline helper.
- The index declared uninitialised at the top of the function and set to zero at the walk.
- The two job set-ups and the submit scope moved into an inlined helper taking the job structs, so the scope is a callee local.
- One permuter run (declaration swaps and moves among them): no candidate better than the start.

## Spelling that fixed it

none
