# 0xd0c7f0 GASFnCall::Arg

<!-- tags: method/diagnostic -->

- Function: 0xd0c7f0 GASFnCall::Arg
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: register-allocation
- Best score: 72/72 (aligned_matching_bytes)
- Attempts: 4

## What differed

Two early returns placed the null return ahead of the paged lookup, and returning the indexed element expression directly allocated the page-table base and element offset in different scratch registers, saving a final register copy compared to the target.

## Spellings tried that did not help

- Guarding with `if (index > topIndex) return nullptr;` before the lookup inverted the branch direction.
- Returning `&stackEnv->pages[index >> 5][index & 0x1F]` directly inside the `if` block kept the shorter register assignment without the trailing copy.
- Storing the page table and value pointer in separate locals inside the `if` block produced the same register choice.

## Spelling that fixed it

Initialize a single result pointer to null and assign it inside the range check using pointer addition, then return it once at the end.

```cpp
GASValue* result = nullptr;
if (index <= topIndex) {
    result = stackEnv->pages[index >> 5] + (index & 0x1F);
}
return result;
```
