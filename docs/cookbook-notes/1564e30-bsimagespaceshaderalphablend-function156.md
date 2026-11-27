# 0x1564e30 BSImagespaceShaderAlphaBlend::Function1564e30

<!-- tags: wall/register-schedule, wall/inlining -->

- Function: 0x1564e30 BSImagespaceShaderAlphaBlend::Function1564e30
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 580/592 (aligned_matching_bytes)
- Attempts: 8

## What differed

After replacing the `this` offset casts with multiple inheritance (`BSImagespaceShader : public OwnerBase0, public ImageSpaceEffect`) and binding the `SpinLockGuard` unwind destructor, every block matches except the scissor-rectangle check. The target loads only the rectangle's `left` field before comparing it to `-1` and reloads `left` only after updating the scissor-mode flag, while leaving `right` as a memory comparison and loading it later for `right - left`.

## Spellings tried that did not help

- Reading `left` and `right` directly from the viewport pointer caused partial redundancy elimination on both `left` and `right`, producing 596 bytes (`560/592`).
- Wrapping the scissor check in a member method on the viewport struct kept the same 596-byte dual-hoist output (`560/592`).
- Passing `const NiRectInt&` to a `SetScissorRect` inline helper eliminated hoisting of both fields, producing 590 bytes (`580/592`).
- Using `NiRectInt::GetWidth()` and `GetHeight()` inline helpers also skipped hoisting of both fields (`577/592`).
- Changing the scissor setter parameter types to `std::uint32_t` with `top`/`height` locals still hoisted both fields (`560/592`).

## Spelling that fixed it

none
