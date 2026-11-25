# 0x14ef80 IngredientItem::LearnNextEffect

<!-- tags: construct/bitfield, wall/flag-fold, wall/register-schedule -->

- Function: 0x14ef80 IngredientItem::LearnNextEffect
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 41/73 matching bytes; distance 14.0; 25 target and 27 candidate instructions
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The flag-word query and update still differ in instruction choice, ordering and loop control flow. The target has fewer instructions. Rule 37 identifies this function as an unresolved flag-word case.

## Spellings tried that did not help
Tried a cached 16-bit flags word, a 32-bit flags word, inline update from the cache, and signed versus unsigned shift literals. The first, second and final spellings stayed at distance 14.0. Bit-test and bit-set intrinsics increased the distance to 18.0. Restored the best ordinary C++ spelling. Three consecutive comparisons did not improve the best.

## Spelling that fixed it
none
