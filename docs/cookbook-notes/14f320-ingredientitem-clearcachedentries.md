# 0x14f320 IngredientItem::ClearCachedEntries

- Function: 0x14f320 IngredientItem::ClearCachedEntries
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 123/123
- Attempts: 3

## What differed

The target updates two cache fields through one shared exit. Keeping a
local count across the empty-array and teardown branches let the compiler
duplicate the stores and restore saved registers on separate paths.

## Spellings tried that did not help

Keeping an initialized count local through the cleanup loop duplicated the
exit. An inlined helper that returned zero on the empty paths and reread
the count on the teardown path also duplicated it.

## Spelling that fixed it

Use the initial count only as the loop counter. Zero the global count on
the null-array path. Read the global once at the common exit and use that
read for both stores. The compiler reuses the previous value where the
loop is skipped and reloads after the loop that can call cleanup.

```cpp
if (entry) {
    if (std::uint32_t remaining = g_entryCount) {
        // Clear the entries, counting down through remaining.
    }
} else {
    g_entryCount = 0;
}
const std::uint32_t count = g_entryCount;
g_entryField1 = count;
g_entryField2 = count;
```
