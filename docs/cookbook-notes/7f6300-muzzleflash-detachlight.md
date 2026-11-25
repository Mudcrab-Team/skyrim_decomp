# 0x7f6300 MuzzleFlash::DetachLight

<!-- tags: wall/register-schedule, construct/destructor, sibling/fo4 -->

- Function: 0x7f6300 MuzzleFlash::DetachLight
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: instruction-order
- Best score: 80/80
- Attempts: 2

## What differed

The release of the light pointer stored null before testing the old pointer for null. The target tests the old pointer first and stores null only inside that branch, then does the atomic decrement.

## Spellings tried that did not help

A smart-pointer assignment that always swaps first (read the old pointer, store the new one, release the old one if set).

## Spelling that fixed it

Give the stand-in smart pointer the usual guarded assignment: compare with the new value first, and only then swap and release. With a null argument the compiler folds the compare into the old-pointer test and stores null after it.

```cpp
NiPointer& operator=(T* a_object)
{
    if (m_pObject != a_object) {
        T* old = m_pObject;
        m_pObject = a_object;
        if (old) {
            old->DecRefCount();
        }
    }
    return *this;
}
```
