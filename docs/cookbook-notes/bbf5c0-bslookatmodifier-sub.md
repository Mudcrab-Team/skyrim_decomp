# 0xbbf5c0 BSLookAtModifier::sub

- Function: 0xbbf5c0 BSLookAtModifier::sub
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: sim 84.4 (Sol; not a byte match)
- Attempts: 7

## What differed
Near-pilot function, Sonnet draft 36.5, Sol 84.4 and Opus 83.1 (not a byte match). The draft used scalar x, y, z, w helpers
and was at the wrong architecture: the target is packed throughout (lane-0 dot products, shuffle broadcast, cross product
through two shuffle selectors, an inverse length from a reciprocal square root plus one Newton step with a zero mask, a
sign-mask conjugate, a masked multiply). The signature from the task's symbol was also wrong: the function returns the clamped
target angle as a float and takes a fifth argument, the maximum angle. Three inherited numeric globals were bound to plausible
but wrong places, and five callees (model-space pose accessor, axis-angle builder, smoothing factor, target-angle helper) had
no hints.

## Spellings tried that did not help
- Load and store helpers on the aligned-load and aligned-store intrinsics (to get aligned moves): -2.3; MSVC 19.16 still emitted
  unaligned moves and the extra temporaries moved the schedule.
- Caching the constants alone: 78.2 (down); delaying the interpolation normalisation, splitting the rotate expression and returning
  the quaternion by value: no gain.
- `std::fabs` on a float expression resolves to the double overload (conversion pairs and a 64-bit mask in the candidate);
  `fabsf` and `acosf` fixed that, but most of the residue was elsewhere.

## Spelling that fixed it
A packed rewrite on a four-lane vector type with the real signature, the bone-data layout and the five bind hints:
+46.5 (Opus) and +42.0 (Sol). Broadcasting the squared length and using one packed product for the real and imaginary quaternion
terms: +1.8. Accumulating the dot product as the target does, y and x first and that sum added to z: +4.3. Left: the bool
argument is homed and compared in memory twice, scalar results go through stack spills before the square root, the Newton
constants are held in two registers across the body, and every pointer access uses unaligned moves where the target folds
aligned loads into memory operands.

The snippet is a generic shape with invented names, not the unit's code.

```cpp
lane0 = z + (y + x);        // the target's accumulation order for the dot product
float angle = acosf(clamped);  // float functions by name; std::fabs would widen to double
```
