# 0x5d16d0 MagicTarget::HasMagicEffect

<!-- tags: construct/loop, wall/control-flow, abi/calling-convention -->

- Function: 0x5d16d0 MagicTarget::HasMagicEffect
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: loop-shape
- Best score: distance 1.0 (from 21); the aligned instruction counts agree; not a byte match
- Attempts: 4 counted comparisons in the structural round (plus earlier history)

## What differed
The observed call set obtains an active-effect list and checks each non-null effect's base object. The target also carries a truth accumulator through a short-circuit list traversal. The draft remains different in list-entry setup, loop branches and frame layout. A full-width return was inferred from the observed return paths, but this alone did not improve the diagnostic score. No comparator pass was obtained.

## Spellings tried that did not help
The combined nonempty-list guard measured 48/137. An early null-list return and explicit iterator selection reached 50/137. Widening the result and accumulator fell to 39/137. Adding the observed short-circuit predicate stayed at 39/137. Naming a reference to the next link and making the exit explicit reached 45/137, below the earlier best. Three consecutive compares without a new best ended the search. The remaining differences were structural, so no register-only search was appropriate.

- Structural reading from the aligned listing (the loop of the sibling visitor units 0x5d18b0 and 0x5d2da0): stop when the node is the empty trailing node (no next link and no effect), stop once a match is found, keep a one-byte accumulator for the match, return it widened. Written as `for (node = list; node && (node->next || node->effect) && !found; node = node->next)` with `bool found`, this took the distance from 21 to 1.0.
- Declaring the accumulator before the list call, initialising it in the same statement as the call, and a byte-sized integer accumulator in place of the bool: all unchanged at 1.0.

## Spelling that fixed it
None yet. The remaining difference is that the target clears the accumulator after the virtual list call while every spelling clears it before the call, plus the order of the last callee-saved register restores. Next ideas: a pointer-to-accumulator helper or a separate inline predicate that returns the accumulator, so that the clear is emitted at the first use after the call.
