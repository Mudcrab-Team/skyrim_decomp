# 0x98a3c0 RenderVolumetricLightingShadowMaps

<!-- tags: method/diagnostic -->

- Function: 0x98a3c0 RenderVolumetricLightingShadowMaps
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 544/671 aligned bytes
- Attempts: 5

## What differed

The caster loop, the render pass setup and the guard around the thread render context lock match. The inlined spin-lock acquire does not: the target stores each compare-exchange result as a flag and tests it, and its sleep loop increments the spin count only below the limit and shares one call to the sleep function. Spelling the delay as a branch kept the shared call but placed the compare before the first sleep; spelling it as a computed delay produced conditional moves.

## Spellings tried that did not help

- Compare-exchange through a helper returning a bool, with the expected value as a parameter or a constant.
- Compare-exchange through std::atomic compare_exchange_strong on a cast pointer.
- Sleep delay as a ternary, as an if/else around two sleep calls, and as a variable set in a branch.

## Spelling that fixed it

none
