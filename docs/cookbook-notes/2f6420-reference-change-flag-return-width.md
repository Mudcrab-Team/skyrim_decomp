# 0x2f6420 TESObjectREFR::Function2f6420

<!-- tags: construct/bitfield, abi/virtual, wall/register-schedule -->

- Function: 0x2f6420 TESObjectREFR::Function2f6420
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 67/76 matching bytes, distance 1.0, equal 76-byte extent
- Attempts: 6

## What differed

A missing loaded-data pointer forwards the change request through a virtual call. With loaded data, the function checks a shifted flag and updates the original flag after a successful change request. The last measured draft differs only in scratch-register allocation during the update. The method name and narrow return signature remain inferred.

## Spellings tried that did not help

A normalized boolean result and a one-bit field introduced a mask that the target did not retain. A separate success branch enlarged the function. A 16-bit flag load followed by narrowing and shifting removed that mask difference. An initial bounded one-worker permutation search on the boolean draft retained distance 2.0. All failed sources and reports remain private.

## Spelling that fixed it

None. The final handwritten draft uses a narrow integer return and preserves the shifted flag value on its fast path. It reaches distance 1.0 but is not a byte match. A second bounded one-worker permutation search was requested for this final register-only residue; it tested 81 candidates and retained distance 1.0. The six-compare cap prevents further counted comparisons in this round.
