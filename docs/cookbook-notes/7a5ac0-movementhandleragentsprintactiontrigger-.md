# 0x7a5ac0 MovementHandlerAgentSprintActionTrigger::~MovementHandlerAgentSprintActionTrigger

<!-- tags: construct/destructor, abi/virtual, sibling/fo4 -->

- Function: 0x7a5ac0 MovementHandlerAgentSprintActionTrigger::~MovementHandlerAgentSprintActionTrigger
- Label: none
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 62/62
- Attempts: 2

## What differed

The destructor of a class with three bases (an agent base, a small virtual interface at offset 0x18, and a second interface at 0x20 whose destructor is an out-of-line call) came out 11 bytes too long. After the call that destroys the 0x20 interface the candidate stored the 0x18 interface's own vtable pointer again before the final tail call to the agent base destructor. The target has no such store, so the 0x18 base has no virtual destructor of its own.

## Spellings tried that did not help

- Giving the 0x18 base an empty inline virtual destructor (this worked for a sibling class where the base destructor call came last, because the dead store was then removed).

## Spelling that fixed it

Give the 0x18 base a plain virtual member instead of a virtual destructor, so it has a vtable pointer but nothing to destroy:

```cpp
class IMovementHandlerInterface { public: virtual void unk00(); };
```
Keep the 0x20 base's inline empty destructor deriving from the out-of-line interface destructor. The same shape closed the scalar deleting destructor 0x7a6430 and the two twins at 0x12211e0 and 0x1221c20. A virtual destructor on that base is still right when the agent base destructor call is the last action (0x7a58a0).
