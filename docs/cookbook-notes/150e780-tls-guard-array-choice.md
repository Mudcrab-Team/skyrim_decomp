# 0x150e780 ShadowSceneNode::AttachObjectToList

<!-- tags: wall/control-flow, abi/exception, method/binding -->

- Function: 0x150e780 ShadowSceneNode::AttachObjectToList (also 0x150e1f0)
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 208/208 and 253/253 bytes with unwind and exception data
- Attempts: 4

## What differed
Both functions hold a spin-lock guard and a per-thread memory-context scope (a thread-local saved, set to a constant, restored).
With the thread-local masking and the written thread-local hint the bytes and unwind data matched at the first try for
0x150e1f0. For 0x150e780 the one open point was how the target picks one of two object arrays to append to.

## Spellings tried that did not help
- `ShadowObjectArray& list = flag ? second : first;` and a pointer picked with `if`: the compiler turns both into a conditional
  move on the two offsets, 3 bytes short.
- `if (flag) second.Append(x); else first.Append(x);`: the same length, but the branch is inverted.

## Spelling that fixed it
`if (!flag) { first.Append(x); } else { second.Append(x); }`. The target loads the first array's address, tests the flag and
overwrites the address only on the second path, which this form gives and the positive test does not. The funclet destructors
for the guard and the scope are found through the function's unwind map (the action addresses of its two states), and
written to the task's bind hints; the thread-local hint is written by `sr bind`.
