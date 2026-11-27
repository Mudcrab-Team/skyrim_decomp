# 0x150e330 ShadowSceneNode::QueueLightRemove

<!-- tags: abi/exception, construct/destructor, wall/callee, method/binding -->

- Function: 0x150e330 ShadowSceneNode::QueueLightRemove (also 0x150cf20, 0x150d120, 0x150cb10)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: other
- Best score: code matched at once; the exception data and unwind info needed four changes
- Attempts: 7

## What differed
These functions hold a spin lock guard (out-of-line constructor, inline unlock in the destructor) and a per-thread
memory-context scope (a value saved at a stack slot, set, restored). The first draft matched the code bytes but failed
`eh-data-mismatch` on the state map: the target has one entry for the throwing call, while the draft also had an entry for
the lock constructor's own call.

## Spellings tried that did not help
- Saving and restoring the context by hand in a local integer: the code shape and the unwind info both changed.
- Constructing the scope as a class but declaring the lock constructor plain.

## Spelling that fixed it
Declare the lock guard's constructor `noexcept` (no ip-to-state entry for its call), keep the context scope as a class with
an inline destructor, and give the exception funclets their out-of-line destructors through the local binding hints
(the guard's and the scope's destructors sit at their own addresses). The same two objects fixed all four functions.
