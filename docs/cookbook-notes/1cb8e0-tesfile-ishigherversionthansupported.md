# 0x1cb8e0 TESFile::IsHigherVersionThanSupported

<!-- tags: method/diagnostic, construct/float, wall/control-flow -->

- Function: 0x1cb8e0 TESFile::IsHigherVersionThanSupported
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: 169/169 (aligned_matching_bytes)
- Attempts: 4

## What differed

Under the default precise floating-point recipe, an early return on `version <= limit` placed the false return at the top of the function, whereas an `if (version > limit)` or `if (limit < version)` body swapped the comparison operand order and used the opposite condition code.

## Spellings tried that did not help

- `if (version <= 1.71f) { return false; } ... return true;` (matched operand order, wrong block layout)
- `if (version > 1.71f) { ... return true; } return false;` (matched block layout, swapped compare operands)
- `if (1.71f < version) { ... return true; } return false;` (same swapped compare operands under precise float)

## Spelling that fixed it

```cpp
if (!(version <= 1.71f)) {
    // format warning and return true
    return true;
}
return false;
```
