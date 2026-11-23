# 0x7e9ad0 Explosion::~Explosion

- Function: 0x7e9ad0 Explosion::~Explosion
- Label: GUESS(low)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 106/106
- Attempts: 7

## What differed

The buffer release has exception-state setup and distinct exits for owned and borrowed storage. The plain reset after the virtual free omitted the exception-state setup. A reset guard scoped to the owned-storage path reproduced the two exits but added a second state store before the call.

## Spellings tried that did not help

A reset guard outside the ownership branch merged the exits. Declaring the virtual free itself nonthrowing lost the exception-state setup. Allowing the destructor to throw retained the extra store.

## Spelling that fixed it

Keep the virtual free potentially throwing. Declare the destructor nonthrowing and scope a guard that resets the backing pointer and capacity to the owned-storage branch. Reset borrowed storage directly on the other branch.

```cpp
~Array() noexcept
{
    size = 0;
    if (OwnsStorage()) {
        const EmptyArrayStorage reset(*this);
        allocator.Free(data, ByteCapacity());
        return;
    }
    data = nullptr;
    capacityAndFlags = kNoOwnedStorage;
}
```
