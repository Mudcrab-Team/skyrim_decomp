# 0x69df00 Actor::IsInFaction

<!-- tags: method/sibling, sibling/f3, wall/layout -->

- Function: 0x69df00 f3m_006f8ff0::Actor::IsInFaction_1405F8500
- Label: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
- Outcome: fixed
- Cause: struct-layout
- Best score: pass on the first attempt with the stand-in
- Attempts: 1

## What differed
The sibling x64 code equals the target except for the constant of an `add reg64, N` that forms the address of a sub-object, and for
a displacement of the member it belongs to. Without treating the add as an offset the layout step has nothing to apply.

## Spellings tried that did not help
- Reading the add constant as an ordinary immediate: the unit then differs from the sibling only by a number nobody writes in
  source, and no spelling of a constant changes an address computation.

## Spelling that fixed it
Treat `add reg64, N` (and `lea reg, [reg + N]`) exactly like a member displacement: find the member of the sibling class that sits at
the sibling's N and place it at the target's N with anonymous padding before it. Excluded from this reading: `add rsp, N`
(frame size) and `add reg32, N` (arithmetic).

```cpp
struct Owner { char padding_0_[0x18]; Set set; };
```
