# 0x4b10e0 BSTempEffectSimpleDecal::ProjectOnto

<!-- tags: abi/exception, construct/allocation, construct/float, construct/loop, construct/switch, construct/vector, method/diagnostic, wall/control-flow, wall/register-schedule -->

- Function: 0x4b10e0 BSTempEffectSimpleDecal::ProjectOnto
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: sim 98.5 (Opus; not a byte match)
- Attempts: 28

## What differed
Near-pilot function, Sonnet draft 65.8, Opus 98.5 in 12 rounds (not a byte match). The draft saved and restored the
allocation tag by hand through a `result` variable and one return. The target stores an unwind state, keeps the saved
tag in a stack slot and shares one exit block between every return: a scope object with early returns. The 3x3 product
was written out with all nine right-hand entries loaded first; the target reads the right-hand matrix one column at a
time (three loads, then three dot products). The inverse was a free helper using `std::abs`, which widens through
double under the default recipe; the target masks the float, compares the magnitude in memory and falls through into
the scaling loop on success. The flip case used `cond ? 1 - u : u` and `u += u`; the target has two store branches.

## Spellings tried that did not help
- The fast-float recipe for the absolute value: +0.3, and it hid the real fix (a branch-select float absolute value gives
  the same mask under the default recipe, which then scored higher than the fast recipe).
- `operator-` and `operator*` on the point type for the sample point: -0.1. Unary minus on the plane normals: -7.8,
  because it reordered the negations; spell the components out where the target's order is not the evaluation order.
- Named normals and planes, an element-wise matrix assignment and persistent basis vectors (Sol): each lowered sim.

## Spelling that fixed it
In order of gain: an allocation-tag scope object, early returns and a matrix `Inverse()` member returning false and
zeroing the result (+12.5); `MakeZero` clearing one column at a time in the target's store order (+2.6); a float
`NiAbs` written as a branch-select, a small `IsKindOf` helper, back to the default recipe (+1.1); a member `operator*`
that loops over the columns of the right-hand matrix (+15.7); success falling through the epsilon test (+0.3); an
if/else store for the U flip (+0.2); `u *= 2.0f` for the default flip (+0.3). What is left is schedule: about 24 bytes
of padding before two loop heads, the store order of the sample point, where the flip byte is loaded, one register
renaming run in the adjugate. Send those to the permuter.

The snippet is a generic shape with invented names, not the unit's code.

```cpp
if (std::fabs(det) <= epsilon) { return false; }   // before: widened through double
if (NiAbs(det) > epsilon) { /* scale the three rows */ return true; }
return false;                                         // after: success falls through
```
