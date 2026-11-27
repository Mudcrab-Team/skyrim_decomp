# 0xdf0e00 GFxDisplayContext::BeginClipLayer

<!-- tags: method/diagnostic -->

- Function: 0xdf0e00 GFxDisplayContext::BeginClipLayer
- Label: CRASHLOGGER_PDB(59818@2026.10.24), GUESS
- Outcome: fixed
- Cause: instruction-order
- Best score: 193/193 (aligned_matching_bytes)
- Attempts: 4

## What differed

Three consecutive counter increments (`clipDepth`, `maskStackSize`, `maskDrawDepth`) before the virtual call to `GetBlendMode` scheduled the `clipDepth` increment two instructions late when `clipDepth` was incremented after `maskStackSize`. Storing the blend mode in a local variable also changed register assignment across the calls.

## Spellings tried that did not help

- Incrementing `maskStackSize`, then `maskDrawDepth`, then `clipDepth` with an inline `GetBlendMode()` call.
- Incrementing `maskStackSize`, then `clipDepth`, then `maskDrawDepth` with `GetBlendMode()` saved to a local variable.
- Incrementing `maskStackSize`, then `clipDepth`, then `maskDrawDepth` with an inline `GetBlendMode()` call.

## Spelling that fixed it

```cpp
++clipDepth;
++maskStackSize;
++maskDrawDepth;
renderer->PushBlendMode(a_char->GetBlendMode());
```
