# 0x150e500 ShadowSceneNode::AttachSceneObjectsToLight

<!-- tags: wall/register-schedule, construct/loop, method/diagnostic -->

- Function: 0x150e500 ShadowSceneNode::AttachSceneObjectsToLight (also 0x150fe80 ShadowSceneNode::ReplaceShadowCasters)
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 203/203 and 85/85 bytes, instructions equal, registers differ
- Attempts: 24

## What differed
Same walls as the two earlier notes on this function, reproduced from a clean unit in the fifth round. 0x150e500 keeps `this` in the
callee-saved register the target gives to the shared zero (the start value of the second loop, also copied into the first loop's index) and the other way
round; every offset and branch is equal. 0x150fe80 keeps the light in its argument register and moves `this` to a scratch register in the target, and
the draft moves both: the light goes to the first free scratch register and the loaded entry takes the light's argument register.

## Spellings tried that did not help
- 0x150e500, on top of the earlier rounds: view pointer instead of the children reference, the zero declared before the first call, the children
  reference declared first, an early return for the missing portal graph, a local copy of the portal graph pointer (one byte short of the size), a signed
  counter (twenty-eight bytes too long). Seven shapes, the same register swap in all but the last two.
- 0x150fe80: entry local with a combined test, swapped compare operands, nested tests, the end bound written inline, a reference to the array slot, the store
  before the shadowmap index write. All five keep the same role swap; the slot reference is seven bytes short.
- Permuter, 481 candidates in 108 s on 0x150e500: best distance 1.0, unchanged from the start state; its best states are the swap itself.
- Checks from the matcher levers that came out clean: argument registers (the light is the only argument that reaches calls and it is already in the
  right register), stores inside or after the tests (identical order), local lifetimes (one index per loop and one shared zero), callee bodies
  (every callee is a separate function in the image, so nothing is inlined).

## Spelling that fixed it
none. Both allocations depend on the allocator's tie-break between two values with the same number of weighted uses, and no source form tried changes the
weights. Next idea: the real function probably calls a small inlined helper per element (so the walk is two helper expansions with their own temporaries),
which would change the weights without changing the instructions.
