# 0x14ef80 IngredientItem::LearnNextEffect

<!-- tags: construct/bitfield, wall/flag-fold, wall/register-schedule -->

- Function: 0x14ef80 IngredientItem::LearnNextEffect
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: instruction-order
- Best score: distance 7.5 (from 14.0); not a byte match
- Attempts: 5 counted comparisons in total

## What differed
The flag-word query and update still differ in instruction choice, ordering and loop control flow. The target has fewer instructions. Rule 37 identifies this function as an unresolved flag-word case.

## Spellings tried that did not help
Tried a cached 16-bit flags word, a 32-bit flags word, inline update from the cache, and signed versus unsigned shift literals. The first, second and final spellings stayed at distance 14.0. Bit-test and bit-set intrinsics increased the distance to 18.0. Restored the best ordinary C++ spelling. Three consecutive comparisons did not improve the best.

- The scan is a bounded for loop over four bits followed by a bounds test before the learn call, not a while loop with a mask that is shifted each round: `for (; index < 4; ++index) if (!(flags & (1u << index))) break; if (index < 4) { learn; return index; } return -1;` with a 32-bit copy of the flag word (distance 7.5). A 16-bit copy and a by-value bit-test helper were worse (10.0 and 10.0).
- What is left: the target tests each bit with a bit-test instruction and a carry branch, the candidate multiplies the mask by a rotate.

## Spelling that fixed it
None. Next idea: find the spelling the compiler turns into a bit-test (a signed shift count, or a flag-word accessor that returns the shifted word).
