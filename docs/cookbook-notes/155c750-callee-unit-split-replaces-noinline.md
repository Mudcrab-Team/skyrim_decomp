# 0x155c750 BSShadowLight::ReleaseShadowmapDescriptor

<!-- tags: wall/inlining, abi/exception, method/diagnostic -->

- Function: 0x155c750 BSShadowLight::ReleaseShadowmapDescriptor (also 0x155c590, 0x155c850, 0x155d890, 0x155d970, 0x155dc00)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 242/242, 172/172, 310/310, 204/204, 179/179 and 281/281 bytes with unwind data, on the PC and on the Mac
- Attempts: 5

## What differed
Six functions of the shadow-light family had matched bytes in one unit, with `__declspec(noinline)` on the array members and on
`ReleaseShadowmapDescriptor` so the callers kept their calls. The reviewer rejected all six: a forced out-of-line call whose only
justification is "the target calls it" reads as a codegen trick. The calls themselves were right; the way of keeping them was not.

## Spellings tried that did not help
- A longer justification comment on each `noinline`: the ground is the attribute, not the wording.
- Declaring the array members without a body but leaving the descriptor destructor `noexcept` and undefined: `Clear` and `SetSize`
  came out 110 of 179 and 231 of 281 bytes, with no exception-state slot and no inlined smart-pointer release.

## Spelling that fixed it
Split the translation unit the way the engine's own build was split. The callee unit defines `SetSize`, `Clear` and
`ReleaseShadowmapDescriptor` (the array members as out-of-class template definitions plus explicit instantiations), and also defines the
descriptor destructor ahead of them, empty, so the member smart pointers are released in place inside `Clear`. The caller unit
(`SetShadowmapCount`, the destructor, the deleting destructor) only sees declarations, so the calls stay calls with no attribute at all.
The header for the pair declares the three array members without bodies. Rule of thumb: when a caller must not inline a callee, keep the
callee's body out of the caller's unit; when the callee itself needs an inlined helper (here the descriptor destructor), keep that helper's body in the callee's unit.
