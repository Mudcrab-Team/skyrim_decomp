# 0x5c0c70 ActorMagicCaster::AdjustLight

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x5c0c70 ActorMagicCaster::AdjustLight
- Label: SIBLING(fo4-private@1b765c70, author-permission) SYMBOLS(tesv-2013-map)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 51/84 aligned matching bytes; alignment distance 4.0; candidate and target both 84 bytes
- Attempts: 5 counted comparisons; 5 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The complete position adjustment retained different floating-point load, subtraction and store ordering and register assignment. The ordinary comparator failed every counted attempt. This is a scheduling diagnosis, not a semantic-equivalence or acceptance claim. Cookbook rules 4 and 45 supplied hypotheses; neither closed it.

## Spellings tried that did not help

- Separate component snapshots followed by three calculations and three stores: 22/84 matching bytes, distance 5.5.
- The bounded one-worker permutation search tried 257 candidates in 64 seconds. Moving each result declaration beside its store produced the best state, 51/84 matching bytes and distance 4.0, confirmed by attempt 2; it still failed.
- A whole-vector snapshot and aggregate assignment expanded to 105 bytes; 1/84 matching bytes, distance 21.0.
- Reverse calculation order with forward stores reached 43/84 matching bytes, distance 6.0.
- Forward calculations without separate component snapshots returned to 22/84 matching bytes, distance 5.5.

## Spelling that fixed it

None. Stopped after three consecutive counted comparisons without improvement over the best. Best source and all failed attempts remain private for follow-up.
