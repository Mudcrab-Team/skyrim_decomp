# 0x1550d20 ImageSpaceEffectDepthOfField::Setup

<!-- tags: wall/inlining, wall/register-schedule -->

- Function: 0x1550d20 ImageSpaceEffectDepthOfField::Setup
- Label: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: inlining
- Best score: 1343/1343 (aligned_matching_bytes)
- Attempts: 5

## What differed

With direct indexing on the effects array, one call to `Function1554150` loaded the array base directly into the third argument register instead of staging it through the return register. Switching all five lookups to a by-value `GetAt` accessor fixed that load, but swapped two callee-saved constant registers across the rest of the function.

## Spellings tried that did not help

- Replacing all five array lookups with a by-value `GetTarget` or `NiTPrimitiveArray::GetAt` accessor fixed the array-base load register, but swapped the two callee-saved constant registers (`1232/1343`).
- Changing `NiTPrimitiveArray::GetAt` to return `const T&` restored the constant registers, but brought back the direct argument-register load (`1335/1343`).
- Adding `MemoryManager::GetSingleton()` and reusing the `param` and `shader` locals kept the constant-register swap (`1232/1343`).

## Spelling that fixed it

Keep `NiTPrimitiveArray::GetAt` returning by value and also read the shader dimensions through inline `GetWidth()` and `GetHeight()` accessors on the derived shader type:

```cpp
std::int32_t GetWidth() const { return width; }
std::int32_t GetHeight() const { return height; }
```
