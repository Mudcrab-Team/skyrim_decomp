# 0x157e490 BSShadowDirectionalLight::BSShadowDirectionalLight

<!-- tags: wall/register-schedule, construct/constructor -->

- Function: 0x157e490 BSShadowDirectionalLight::BSShadowDirectionalLight
- Label: CRASHLOGGER_PDB(59818@2026.10.24); GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: size 1114/1114, registers differ
- Attempts: 13

## What differed

The size matches and every instruction is present, but the callee-saved registers are handed out in another order: the target keeps the zero in the second saved register, the array address in the fourth and the thread-local pointer in the fifth, the draft starts the zero in the fifth. The clamp of the sun angle needed explicit scalar min and max (a branchy ternary or std::min and std::max both left branches, and /fp:fast did not change that); only the intrinsic chain, with the multiply in the same chain, gave the same instructions.

## Spellings tried that did not help

- Ternary clamp, std::min and std::max, and the fast-float recipe: all kept compare-and-branch pairs.
- Intrinsic min and max with the multiply outside the chain: a register move differed.
- The permuter ran 481 candidates and kept the draft as its best.

- Retry: scalar ternaries on locals (size 1127, branches again); float helper functions around the intrinsics with a literal zero (a second zero constant and two extra moves); the intrinsic min and max chain with the multiply done on plain floats afterwards (puts the result straight into the call argument register, size equal, but the zero is a second clear instead of the one shared with the cache test). The chain fully inside the vector type shares the zero but needs one extra register move into the argument register. None of the five spellings changed the order in which the callee-saved registers are handed out.

## Spelling that fixed it

none
