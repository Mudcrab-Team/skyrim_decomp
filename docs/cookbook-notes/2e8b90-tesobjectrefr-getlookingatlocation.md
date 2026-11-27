# 0x2e8b90 TESObjectREFR::GetLookingAtLocation

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x2e8b90 TESObjectREFR::GetLookingAtLocation
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 253/284 (aligned_matching_bytes)
- Attempts: 6

## What differed

With fast floating-point flags, user-defined `NiPoint3` constructors, pointer-returning `GetBoundMax`/`GetBoundMin` virtuals, and a two-element `NiPoint3 bounds[2]` array, the candidate reproduced the exact size and every byte up to the midpoint arithmetic, where the compiler loaded the half-scale constant first and added `max` into `min` instead of `min` into `max`.

## Spellings tried that did not help

- Compiling with default `/fp:precise` and value-returning `NiPoint3` operators (emitted parity checks and out-of-line operator calls).
- Switching to `o2-fpfast.json` and writing scalar component arithmetic with value-returning virtuals.
- Returning `NiPoint3*` from `GetBoundMax`/`GetBoundMin` into two separate `NiPoint3` locals (placed the second local at sixteen-byte alignment instead of twelve-byte stride).
- Adding user-defined `NiPoint3` default, component, and copy constructors (closed the 3D world-bound return copy).
- Packing the two temporary bounds in `NiPoint3 bounds[2]` and trying both `(maxPtr + minPtr)` and `(minPtr + maxPtr)` orders with both `extern float` and literal `0.5f`.

## Spelling that fixed it

none
