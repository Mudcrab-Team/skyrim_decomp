# 0x552eb0 IAnimationGraphManagerHolder::HasAnimationGraphManager

<!-- tags: wall/register-schedule -->

- Function: 0x552eb0 IAnimationGraphManagerHolder::HasAnimationGraphManager
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 68/78 matching bytes; distance 1.0; 21 target and candidate instructions
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The best source has the same instruction count, with two register-renaming differences. No byte match was obtained.

## Spellings tried that did not help
An implicit destructor exception specification added cleanup differences. Caching the manager pointer and using a throwing destructor reduced the measured distance from 3.0 to 1.0. An inline decrement helper and std::atomic fetch_sub stayed at distance 1.0. Two bounded PC permutation runs exhausted their pools without a winner. The best original spelling was restored for the final comparison.

## Spelling that fixed it
none
