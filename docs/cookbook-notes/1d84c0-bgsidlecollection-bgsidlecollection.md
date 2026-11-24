# 0x1d84c0 BGSIdleCollection::~BGSIdleCollection

- Function: 0x1d84c0 BGSIdleCollection::~BGSIdleCollection
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: inlining
- Best score: 212/212
- Attempts: 4

## What differed

The deleting destructor kept its terminate-on-exception state active through the field resets and the base destructor. The target ended that state immediately after the heap calls.

## Spellings tried that did not help

An inline member for the entire cleanup kept the later state boundary, with or without an explicit nonthrowing specification. Saving and restoring the context directly changed the saved registers as well.

## Spelling that fixed it

The inline nonthrowing helper contains only heap initialization and deallocation. The cleanup member sets up the allocation context, calls that helper and then clears the count and array pointer.

```cpp
inline void ReclaimIdleStorage(void* idleArray) noexcept
{
    if (g_memoryManagerGuard != 2)
        g_memoryManager.EnsureInit(&g_memoryManagerGuard);
    g_memoryManager.Deallocate(idleArray, false);
}
```
