# 0x83fd30 CombatMagicCasterBoundItem::~CombatMagicCasterBoundItem

<!-- tags: construct/destructor, method/binding -->

- Function: 0x83fd30 CombatMagicCasterBoundItem::~CombatMagicCasterBoundItem (also applies to 0x83f2f0 CombatMagicCasterCloak::~CombatMagicCasterCloak)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: other
- Best score: 109/109 (aligned_matching_bytes)
- Attempts: 5

## What differed

Two issues blocked exact matching on deleting destructors of `CombatMagicCaster` subclasses:

1. Defining only `~Class() = default;` did not emit a scalar deleting destructor (`??_G...`) in the object file unless a constructor also referenced the class vftable, and the binder needed the `// CI hash: 0x<rva> ??_G...` line to select the deleting destructor instead of the complete destructor (`??1...`).
2. Inside the inline `NiPointer` member destructor, decrementing `ptr->refCount` directly through `this->ptr` caused MSVC to reload `this->ptr` from memory after the atomic decrement (`_InterlockedExchangeAdd`), adding an extra load instruction.

## Spellings tried that did not help

- Defining only `~CombatMagicCasterBoundItem() = default;` without a constructor definition: no scalar deleting destructor emitted in the object file.
- Writing `if (ptr && _InterlockedExchangeAdd(&ptr->refCount, -1) == 1) { ptr->DeleteThis(); }`: reloaded `ptr` from memory after the atomic operation because the compiler treated the atomic intrinsic as potentially aliasing `this->ptr`.

## Spelling that fixed it

Add a `// CI hash:` line naming the scalar deleting destructor, define both the default constructor and default destructor in the `.cpp`, and copy `ptr` to a local pointer before the atomic decrement:

```cpp
~NiPointer83fd30()
{
    T* old = ptr;
    // intrinsic: atomic refcount decrement on smart pointer release
    if (old && _InterlockedExchangeAdd(&old->refCount, -1) == 1) {
        old->DeleteThis();
    }
}
```
