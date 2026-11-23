# 0x21cba0 NiAVObject::Function21cba0

- Function: 0x21cba0 NiAVObject::Function21cba0
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 103/103
- Attempts: 5

## What differed

The candidate selected a fresh null result rather than selecting in the saved object pointer after the runtime type check.

## Spellings tried that did not help

- Returning a conditional expression after computing the match flag.
- Setting the pointer to null on a mismatch and returning it.
- Inverting the match flag before the pointer selection.

## Spelling that fixed it

```cpp
if (matches) return object;
return nullptr;
```

The flag is computed in an explicit null-checking branch before these returns.
