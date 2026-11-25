# 0x5d16d0 MagicTarget::HasMagicEffect

<!-- tags: construct/loop, wall/control-flow, abi/calling-convention -->

- Function: 0x5d16d0 MagicTarget::HasMagicEffect
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 50/137 aligned matching bytes
- Attempts: 5

## What differed
The observed call set obtains an active-effect list and checks each non-null effect's base object. The target also carries a truth accumulator through a short-circuit list traversal. The draft remains different in list-entry setup, loop branches and frame layout. A full-width return was inferred from the observed return paths, but this alone did not improve the diagnostic score. No comparator pass was obtained.

## Spellings tried that did not help
The combined nonempty-list guard measured 48/137. An early null-list return and explicit iterator selection reached 50/137. Widening the result and accumulator fell to 39/137. Adding the observed short-circuit predicate stayed at 39/137. Naming a reference to the next link and making the exit explicit reached 45/137, below the earlier best. Three consecutive compares without a new best ended the search. The remaining differences were structural, so no register-only search was appropriate.

## Spelling that fixed it
None. Recover the original iterator or visitor boundary before additional scheduling experiments. The best diagnostic score predates the later semantic corrections and is not a byte-match claim.
