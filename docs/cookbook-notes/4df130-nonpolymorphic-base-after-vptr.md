# 0x4df130 PathingCoverLocation scalar deleting destructor

<!-- tags: abi/virtual, construct/destructor, method/diagnostic, wall/inlining, wall/layout -->

- Function: 0x4df130 PathingCoverLocation scalar deleting destructor
- Label: EXE_RTTI
- Outcome: fixed
- Cause: struct-layout
- Best score: 66/66
- Attempts: 1

## What differed

The wrapper stores the class vftable, then calls the base destructor on `this + 8`, although RTTI
lists the base as a single-inheritance base. The base has no vftable, so MSVC places the derived
vptr first and the base after it.

## Spellings tried that did not help

none

## Spelling that fixed it

Declare the base without virtual functions and with an out-of-line non-virtual destructor, and give
the derived class the root inline virtual destructor. MagicItemData has the same shape with a BSString
member at 8 instead of a base.

```cpp
class BSPathingLocation { public: ~BSPathingLocation(); char unk00[0x60]; };
class PathingCoverLocation : public BSPathingLocation {
public:
    PathingCoverLocation();
    virtual ~PathingCoverLocation() {}
};
```
