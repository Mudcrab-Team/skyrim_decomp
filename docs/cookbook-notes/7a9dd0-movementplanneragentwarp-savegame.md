# 0x7a9dd0 MovementPlannerAgentWarp::SaveGame

<!-- tags: construct/serialization, abi/virtual, sibling/fo4 -->

- Function: 0x7a9dd0 MovementPlannerAgentWarp::SaveGame
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 123/123
- Attempts: 2

## What differed

Everything matched except the two virtual calls on the stream object: the float write and the unsigned write went through the wrong table slots. The stand-in stream class declared its same-named write overloads in the order of the slots, so the compiler assigned the slots the other way round.

## Spellings tried that did not help

Declaring the overloads in the observed slot order (float first, unsigned later): the float write landed in the wrong slot.

## Spelling that fixed it

Declare the overloaded virtuals of one name in reverse of the observed slot order, together, with placeholder overloads between them. MSVC lays a group of same-named virtuals out last declared first, so the overload declared last gets the lowest slot of the group.

```cpp
virtual void DoWrite(unsigned int a_value);    // slot 4
virtual void DoWrite(unsigned short a_value);  // slot 3
virtual void DoWrite(unsigned char a_value);   // slot 2
virtual void DoWrite(float a_value);           // slot 1
```
