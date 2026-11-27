# 0x1586860 BSImagespaceShaderWaterFlow::Function1586860

<!-- tags: method/diagnostic -->

- Function: 0x1586860 BSImagespaceShaderWaterFlow::Function1586860
- Label: GUESS(low)
- Outcome: fixed
- Cause: constant-folding
- Best score: 122/122
- Attempts: 2

## What differed

Stores of zero to globals came out as `xor eax,eax` plus register stores. The target stores an immediate zero to each global.

## Spellings tried that did not help

None, the type was the cause.

## Spelling that fixed it

Declare the zeroed globals as `float` and assign `0.0f`; the compiler stores the immediate 32-bit zero. The same globals as `int` gave the zeroed-register form.
