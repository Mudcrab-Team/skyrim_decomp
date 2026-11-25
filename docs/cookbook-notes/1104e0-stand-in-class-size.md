# 0x1104e0 scalar deleting destructor of a sibling-shaped stand-in class

<!-- tags: construct/destructor, wall/layout, sibling/fo4 -->

- Function: 0x1104e0 Owner1104e0::~Owner1104e0 (same shape at 0x12dd70, 0x58f0a0, 0x15832a0)
- Label: GUESS(low) (the sibling decompilation only pointed at the shape)
- Outcome: fixed
- Cause: struct-layout
- Best score: 47/52 aligned bytes with the sibling class pasted in, 52/52 with a sized stand-in
- Attempts: 1 counted with the pasted sibling class, 1 counted with the sized stand-in

## What differed
The compiler-generated deleting destructor calls the sized `operator delete` with the class size. The
sibling's class layout (a 32-bit build, with its own member list) is larger than the Skyrim class by
0x20 bytes, so the one differing instruction loads that size and the rest of the 52-byte function is equal.
The pasted class also needed a long chain of sibling declarations to compile at all.

## Spellings tried that did not help
- Pasting the sibling class and its dependencies into the unit header (declarations resolved, size still wrong).

## Spelling that fixed it
Do not take the layout from the sibling for a deleting-destructor thunk. Use a class with a virtual
destructor, no members except one opaque array that pads it to the size the target passes to delete, and an
empty constructor so the vftable and the deleting destructor are emitted. `sibling_transplant.py run --sizes`
builds exactly this from the size alone.

```cpp
class Owner1104e0
{
  public:
    Owner1104e0();
    virtual ~Owner1104e0();
    char padding_[0xf0];  // class size 0xf8
};
```
