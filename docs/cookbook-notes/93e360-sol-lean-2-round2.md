# 0x93e360 Inventory3DManager::GetLastModelPosition

<!-- tags: wall/control-flow, wall/register-schedule -->

- Function: 0x93e360 Inventory3DManager::GetLastModelPosition
- Label: GUESS(low)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 70/91 matching bytes; distance 4.5; 24 target and candidate instructions
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
Scalar position copying improved the candidate, but conditional path layout and instruction scheduling still differ. The precise remaining source cause is unresolved.

## Spellings tried that did not help
Whole-structure assignment started at distance 18.0. Separate scalar field copies reached distance 4.5. Explicit inline-versus-heap storage selection and a by-value result with a scalar copy constructor stayed at 4.5. A bounded PC permutation run exhausted its pool at 4.5. Initializing the fallback pointer before the condition worsened the score to 9.5. Restored the best source for final comparison.

## Spelling that fixed it
none
