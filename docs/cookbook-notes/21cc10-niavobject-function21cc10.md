# 0x21cc10 NiAVObject::Function21cc10

- Function: 0x21cc10 NiAVObject::Function21cc10
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 113/113
- Attempts: 9

## What differed

The compiler merged the two flag tests or chose individual bit tests. The target kept two separate mask tests after the type check.

## Spellings tried that did not help

- Combining the two mask tests with a logical OR.
- Testing the bits as bit-fields with separate returns.
- Separate mask tests used as boolean conditions.

## Spelling that fixed it

After the null and runtime type checks, separate early returns comparing each unsigned mask result to zero produced the target:

```cpp
if ((flags & firstMask) > 0) return object;
if ((flags & secondMask) > 0) return object;
return nullptr;
```
