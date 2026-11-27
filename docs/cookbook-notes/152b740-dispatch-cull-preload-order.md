# 0x152b740 BSCullingProcess::DispatchCullAndAccumulate

<!-- tags: construct/switch, wall/inlining, wall/register-schedule -->

- Function: 0x152b740 BSCullingProcess::DispatchCullAndAccumulate
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 423/485 aligned bytes (123/123 instructions, 486 vs 485 bytes)
- Attempts: 7

## What differed

The static local thread-safe initialization of the standard and parabolic culling processes, memory-context guard, and post-pass cleanup match, with identical instruction counts (123/123). Inside the cull-mode dispatch, the candidate loads `camera` before `sceneRoot`, clobbering the scratch register holding the returned process pointer and forcing an extra REX-prefixed register for the virtual dispatch (+1 byte).

## Spellings tried that did not help

- Factoring the cull-mode dispatch into an inline helper with `sceneRoot` then `camera` locals (423/485 aligned bytes).
- Swapping the local load order inside the inline helper to `camera` then `sceneRoot`.
- Writing the cull-mode `if/else if` chain directly in the function body without the helper (dropped to 337/485).

## Spelling that fixed it

none
