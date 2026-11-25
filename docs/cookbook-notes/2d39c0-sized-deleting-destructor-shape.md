# 0x2d39c0 TESObjectCELL::~TESObjectCELL

<!-- tags: construct/destructor, method/sibling, sibling/fnv, wall/layout -->

- Function: 0x2d39c0 TESObjectCELL::~TESObjectCELL
- Label: GUESS(low)
- Outcome: fixed
- Cause: struct-layout
- Best score: 12 of 12 size-only thunks of the 52-byte shape pass
- Attempts: 1

## What differed
A sibling deleting-destructor thunk matches the target except for the size handed to the delete call. The unit needs only a
class with a virtual destructor, an empty constructor that makes the compiler emit the vftable, and padding so that the class
has the target's size.

## Spellings tried that did not help
- Thunks whose target is larger than the 52-byte shape (56, 62, 66, 76, 89 bytes in earlier rounds, 125 pairs): the target
  inlines the destructor body (member releases, base destructor calls), so no size alone reproduces it. Attempts at these
  fail with a size mismatch whatever the padding; filter on the target function size before spending a compare.
- Routing a size-only thunk through the stand-in layout path with its excerpted class: the class text of large sibling units does not
  compile on its own, and the result is a compile failure rather than a size answer.

## Spelling that fixed it
Take the size from the layout fact keyed by the Skyrim owner, write the class with `char padding_[size - 8]`, and keep the
size-only path for pairs whose only fact is the class size.

```cpp
class TESObjectCELL { public: TESObjectCELL(); virtual ~TESObjectCELL(); char padding_[0x40]; };
TESObjectCELL::TESObjectCELL() {}
```
