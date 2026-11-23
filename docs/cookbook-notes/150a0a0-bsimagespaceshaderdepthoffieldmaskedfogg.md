# 0x150a0a0 BSImagespaceShaderDepthOfFieldMaskedFogged::Unk_0D

- Function: 0x150a0a0 BSImagespaceShaderDepthOfFieldMaskedFogged::Unk_0D
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 50/50
- Attempts: 6

## What differed

The candidate computed the third pointer before storing the second; the target performed the store first.

## Spellings tried that did not help

- Indexed stores in source order.
- Moving the empty-string store and naming the second pointer.
- Naming the repeated empty-string pointer.

## Spelling that fixed it

A moving output pointer kept the stores in source order:

```cpp
*out++ = first;
*out++ = empty;
*out++ = second;
*out++ = empty;
```

The unit continues with two null entries and returns the original output pointer.
