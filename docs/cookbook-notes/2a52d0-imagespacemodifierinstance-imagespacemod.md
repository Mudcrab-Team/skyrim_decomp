# 0x2a52d0 ImageSpaceModifierInstance::~ImageSpaceModifierInstance

<!-- tags: method/diagnostic -->

- Function: 0x2a52d0 ImageSpaceModifierInstance::~ImageSpaceModifierInstance
- Label: GUESS(low)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 128/128
- Attempts: 4

## What differed

All instructions matched, but the callee-saved register was saved in the first home slot where the target uses the second. The same shift blocked the Atmosphere constructor 0x40b4f0 and the water displacement effect deleting destructor 0x155c090. Each inlines a smart-pointer reference release.

## Spellings tried that did not help

A null assignment of the smart-pointer member in several shapes, a temporary guard object, copy and move assignment through a temporary, and a noexcept release helper. All gave the same slot.

## Spelling that fixed it

Keep the result of the interlocked decrement in a local before testing it. The local is optimised away but still reserves the first home slot. This one change closed all three functions. The Atmosphere constructor still needs a private symbol binding, so it is not submitted with this note. Atmosphere also needed a declared smart-pointer destructor so that the exception state count matched.

```cpp
const long count = _InterlockedDecrement(&m_uiRefCount);
if (count == 0) {
    DeleteThis();
}
```
