# 0xcdf660 ScrapHeap::Allocate

<!-- tags: construct/allocation, construct/bitfield, construct/loop, construct/switch, method/diagnostic, wall/constant, wall/control-flow, wall/flag-fold, wall/layout, wall/register-schedule -->

- Function: 0xcdf660 ScrapHeap::Allocate
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: branch-layout
- Best score: sim 85.9 (Opus; not a byte match)
- Attempts: 16

## What differed
Near-pilot function, Sonnet draft 73.3, Opus 85.9 in 12 rounds (not a byte match). Three differences. The draft kept
a boolean (`inFreeLists`) to remember where the block came from; the target has no such state: each search stage is
guarded by `if (!found)` and the end is `if (!found) { grow } else { remove the free block }`. The tree best-fit descent
was a nested if/else with an inverted branch. A behaviour defect the similarity score barely sees: the tree
realignment added 0x10 to the block start where the target adds 0x20 (the score moved by a fraction of a point; a
re-read of the constants found it, and the behaviour-mismatch count of `tools/verifier/align.py` flags it).

## Spellings tried that did not help
- Moving the split after the loop (`do { } while (!found)`): no change.
- The retry block in the grow-failure path with the split unconditional: -1.5. Hoisting `bestWaste` out of the outer tree
  loop: -0.5.
- Factoring payload and block navigation into helpers: changed the mask hoisting and lowered sim.
- A `uint32_t` for `bestWaste` and a second load of the last block's size word were also wrong (the target loads it once).

## Spelling that fixed it
Drop the invented flag for `if (!found)` chains; write the tree descent flat, as a record step
`if (size fits && size < best)` followed by `if (payload < size) go left; else if (payload > size) go right;`; use +0x20
in the realignment (together +8.5). The grow path computes `lastEnd` and a gap and realigns when the gap is between 0
and 0x30 (+1.2); a small in-order successor helper with a null guard (+0.5); the small-list search tests the aligned
case first (+1.0) and indexes from `payload >> 3` (+1.2). Left as block-order and register walls: the target shrink-wraps
the early return, keeps a 32-bit all-ones constant in a register for the whole function, records the best fit with a
branch where the draft has a conditional move, and puts the retry block inside the split region.

The snippet is a generic shape with invented names, not the unit's code.

```cpp
found = nullptr;
if (!found) { found = SearchSmallLists(size); }
if (!found) { found = SearchLastBlock(size); }
if (!found) { found = SearchTree(size); }
if (!found) { found = Grow(size); } else { RemoveFreeBlock(found); }
```
