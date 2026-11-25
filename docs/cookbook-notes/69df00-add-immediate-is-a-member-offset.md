# 0x69df00 Actor::IsInFaction

<!-- tags: method/sibling, sibling/f3, wall/layout -->

- Function: 0x69df00 f3m_006f8ff0::Actor::IsInFaction_1405F8500
- Label: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
- Outcome: fixed
- Cause: struct-layout
- Best score: pass on the first attempt with the stand-in
- Attempts: 1

## What differed
The sibling x64 code equals the target except for one constant that forms the address of a sub-object, and for a displacement of
the member it belongs to. Without treating that constant as an offset the layout step has nothing to apply.

## Spellings tried that did not help
- Reading the constant as an ordinary integer: the unit then differs from the sibling only by a number nobody writes in
  source, and no spelling of a constant changes an address computation.

## Spelling that fixed it
Treat a constant added to an object address (also one folded into an address expression) exactly like a member displacement: find
the member of the sibling class that sits at the sibling's offset and place it at the target's offset with anonymous padding
before it. Excluded from this reading: constants that size the stack frame and plain integer arithmetic.

```cpp
struct Owner { char padding_0_[0x18]; Set set; };
```
