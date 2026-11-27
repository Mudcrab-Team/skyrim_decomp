# 0x150e500 ShadowSceneNode::AttachSceneObjectsToLight

<!-- tags: wall/register-schedule, construct/loop, method/diagnostic -->

- Function: 0x150e500 ShadowSceneNode::AttachSceneObjectsToLight (also 0x150fe80)
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 203/203 and 85/85 bytes, instructions equal, registers differ
- Attempts: 14

## What differed
0x150e500: `this` is kept in the callee-saved register that the target gives to the zero counter and the other way round; every
instruction and offset is equal. 0x150fe80: the light parameter stays in its argument register in the target and `this` moves to
a scratch register, while the draft moves the light and `this` and puts the loaded entry in the argument register.

## Spellings tried that did not help
- Permuter, 480 candidates each, twice (rounds two and three): best distance 1.0 and 9.0, unchanged.
- Rule 71 (a one-member class-type counter): changed the size (214 against 203).
- One shared index declared before the first call, a `while` loop for the first walk, the parameters used as loop variables,
  a named entry local, nested tests, the compare operands swapped, a count-based loop (96 against 85).

## Spelling that fixed it
none. The drafts are parked privately. The register roles must come from a different live range or exit structure, not from
a respelling of the counter (rule 12).
