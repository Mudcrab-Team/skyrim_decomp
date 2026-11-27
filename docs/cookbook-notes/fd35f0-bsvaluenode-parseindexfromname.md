# 0xfd35f0 BSValueNode::ParseIndexFromName

<!-- tags: construct/switch -->

- Function: 0xfd35f0 BSValueNode::ParseIndexFromName
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: switch-lowering
- Best score: 141/141 (aligned_matching_bytes)
- Attempts: 4

## What differed

First, testing character membership with range comparisons produced branch chains instead of a range-check plus bitmask test. Switching to a `switch` statement over the accepted characters lowered to the exact bitmask test. Second, computing the trailing substring pointer into a new local pointer let the compiler avoid copying the updated base pointer before checking for the null terminator and calling `atoi`.

## Spellings tried that did not help

- Range comparisons (`(ch >= '0' && ch <= '9') || ch == '#' || ch == '@'`): lowered to separate branches instead of a bitmask test.
- Computing `const char* start = str + (len - offset + 1);` into a fresh local pointer: folded the pointer addition directly into the first argument register and omitted the copy.
- Computing an index variable `startIdx` and passing `&str[startIdx]`: identical register folding to the fresh local pointer.

## Spelling that fixed it

```cpp
switch (str[len - offset]) {
case '#': case '0': case '1': case '2': case '3': case '4':
case '5': case '6': case '7': case '8': case '9': case '@':
    valid = true;
    break;
}
// After the loop, advance the existing pointer in place:
str += len - offset + 1;
const bool hasDigits = (*str != 0);
value = std::atoi(str);
return hasDigits;
```
