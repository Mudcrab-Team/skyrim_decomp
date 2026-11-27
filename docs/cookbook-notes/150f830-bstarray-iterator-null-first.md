# 0x150f830 ShadowSceneNode::GetActiveLightAt

<!-- tags: construct/loop, method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0x150f830 ShadowSceneNode::GetActiveLightAt (also 0x150f8b0, 0x150f710, 0x150f7b0, 0x150fe20, 0x150f340, 0x1511f00)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: branch-layout
- Best score: seven functions went from 9 to 21 matching bytes (size off by 3 to 11) to a byte match
- Attempts: 6

## What differed
Every loop over a `BSTArray` of light pointers (shadow scene node arrays) had the same two differences from the target. The
begin and end of an empty array were written `size ? data : null`, which lays out the data path first; the target tests
the size and falls through to the null path, with the data path after the jump. The `&&` loop conditions (`it != end &&
!found`) also lacked the flag bits the target keeps in a stack home slot, and the copy of the end value cost registers.

## Spellings tried that did not help
- Plain pointer begin and end, written inline in the loop (size 98 against 90).
- A range-style loop: it computes the end once, the target recomputes it every pass.
- The permuter on the loop bodies (best distance never moved): the cause was in the container, not in the body.

## Spelling that fixed it
Take the container from the sibling `BSTArray`: `begin()` and `end()` return `BSTArrayIterator<T>(0)` first when the size is
zero, then the data pointer (null path first); the iterator is a class with a user-provided empty destructor and a copy
constructor. The empty destructor is what makes the compiler keep the "temporary constructed" bit for the `&&` condition.
Loops then read `for (auto it = a.begin(); it != a.end() && !result; ++it)`. All seven loops passed with no per-function edit.
