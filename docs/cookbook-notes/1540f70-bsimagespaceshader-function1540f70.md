# 0x1540f70 BSImagespaceShader::Function1540f70

- Function: 0x1540f70 BSImagespaceShader::Function1540f70
- Label: GUESS(low)
- Outcome: fixed
- Cause: constant-folding
- Best score: 39/39
- Attempts: 4

## What differed

The candidate stored a zero constant directly to a member; the target used a zero value already held in a register.

## Spellings tried that did not help

- Assigning zero directly and returning the member.
- Value-initializing the member and returning zero.
- Assigning and returning a local zero.

## Spelling that fixed it

```cpp
std::memset(&unk58, 0, sizeof(unk58));
return unk58;
```
