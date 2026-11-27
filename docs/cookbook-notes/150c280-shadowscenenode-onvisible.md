# 0x150c280 ShadowSceneNode::OnVisible

<!-- tags: construct/loop, abi/exception, wall/inlining -->

- Function: 0x150c280 ShadowSceneNode::OnVisible
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 1149/1149
- Attempts: 5

## What differed
After binding everything (one binding hint, the memset thunk, was for another function's address and had to be replaced by the pack's own), four small shape differences remained: the load of the camera comes before the index store, the null-graph path is the else-arm at the end rather than an early return, a counted child loop that starts at a constant uses a 32-bit counter whose entry test compares against the 16-bit field, and an unused stack-built object (a compound frustum constructed and destroyed around the walk) is constructed after the iterator start is read, not before. The restore loop over the always-render objects has no outer count test; only the loop's own entry and bottom tests.

## Spellings tried that did not help
- `if (!graph) { base call; return; }` ahead of the body: the base call falls through instead of sitting at the end.
- A 16-bit loop counter for the children: 16-bit increments and a widening of the index on every pass.
- Declaring the unused object first, then reading `begin()` in the `for` header.
- An explicit `if (count)` around the restore loop: a second count call that the target does not have.

## Spelling that fixed it
`if (graph) { ... } else { base call; }`; a 32-bit counter starting at 4 against the 16-bit field; `auto it = rooms->begin();` before the object declaration and `while (it != rooms->end())` after it; the restore loop as a bare `for` over `GetAlwaysRenderCount()`. The per-iteration re-read of the end pointer (`it != cache->rooms.end()` through the process each pass) is what the target does and what the `for` with `end()` in the condition gives.
