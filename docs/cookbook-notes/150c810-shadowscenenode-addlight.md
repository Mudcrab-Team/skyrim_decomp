# 0x150c810 ShadowSceneNode::AddLight

<!-- tags: abi/exception, construct/float, construct/allocation, wall/control-flow -->

- Function: 0x150c810 ShadowSceneNode::AddLight
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: other
- Best score: 758/758
- Attempts: 6

## What differed
Three separate things, one after the other. First the lock release was an out-of-line call: the unit has to define the lock release body so that every guard inlines it. Then the field-of-view tests were in the wrong operand order: the target loads the field once and compares it against a constant read straight from memory, with the frustum light as the fall-through arm, while the plain `field < constant` spelling loads the constant into a register and compares the other way round. Last, with all instructions identical the exception tables still differed: the target had three more IP-to-state entries than the draft.

## Spellings tried that did not help
- `if (fov >= pi) { parabolic } else { frustum }`: the compare operand order is right but the layout puts the parabolic arms first and the branch polarity flips.
- `fov < pi` with the frustum light as the then-arm: the constant sits in a register and the compare operands are reversed.
- Reading the bias through the field directly: the float is copied through an integer register instead of a float register.

## Spelling that fixed it
Negated tests keep the frustum arm first with the memory-constant compare: `if (!(fov >= pi)) {...} else if (!(fov >= twoPi)) {...} else {...}`. A named float local for the bias (`float bias = params->depthBias;`) switches the copy to a float-register move. For the exception tables: the shadow-light class `operator new` must not carry `throw()`. With `throw()` the compiler knows the allocation call cannot throw and drops the IP-to-state entry at each of the three allocation calls (three entries short); without it the null checks stay (the default does not assume a throwing new) and the entries appear. Rule 26 names the `n_ip_map` count but guessed a callee defined in the same unit; here it was a nothrow declaration.
