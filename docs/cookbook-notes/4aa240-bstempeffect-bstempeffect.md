# 0x4aa240 BSTempEffect::BSTempEffect

- Function: 0x4aa240 BSTempEffect::BSTempEffect
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: other
- Best score: 62/62
- Attempts: 2

## What differed

The derived constructor needs unwind cleanup for both its base and its first
smart-pointer member. The visible initialization only supplies null pointers,
yet the exception metadata still describes both cleanup states.

## Spellings tried that did not help

Plain pointer member initialization omitted the exception state and changed
the frame. Using a nullable smart-pointer constructor followed by a direct
null value for the file name matched the main instructions but generated
only the base cleanup state.

## Spelling that fixed it

Construct the first member through a nullable pointer constructor with a
non-null retain path. Initialize the file name through an inline nullable
copy helper whose non-null path can allocate. The compiler folds the
non-null paths out of this constructor while retaining both cleanup states.
Bind the emitted smart-pointer destructor to the cleanup reference in the pack.

```cpp
BSTempEffect::BSTempEffect() :
    BSTempEffectBase(nullptr, 0.0f),
    debris3D(nullptr),
    debrisFileName(DuplicateDebrisFileName(nullptr)),
    unk40(0)
{
}
```
