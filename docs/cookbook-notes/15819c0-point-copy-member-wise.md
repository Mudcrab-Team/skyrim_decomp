# 0x15819c0 BSShadowDirectionalLight::UpdateSunDirection

<!-- tags: wall/register-schedule, construct/float, wall/flag-fold -->

- Function: 0x15819c0 BSShadowDirectionalLight::UpdateSunDirection (also 0x1588c80, 0x1516b90)
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: size and every instruction equal, then a byte match; each took three or four compares
- Attempts: 4

## What differed
0x15819c0 copies a three-float direction in both branches. With a plain struct assignment the compiler used an 8-byte plus a
4-byte move and hoisted the first load above the division, so the order of loads and stores differed from the target's three
interleaved 4-byte moves; the permuter reached distance 0.5 and stopped. 0x1588c80 chooses 1.0 or -1.0 for a global per loop
pass; written as a preset (`side = 1.0f; if (...) side = -1.0f;`) the select was hoisted before the compare. 0x1516b90 stores two
flags in a small stack record; a 16-bit constant store was spelled as a load into a register first.

## Spellings tried that did not help
- Component-wise copies written as three statements (still hoisted the first load).
- The permuter on 0x15819c0 (distance 0.5, pool exhausted).
- A 16-bit member for the two flags.

## Spelling that fixed it
Give the point type a member-wise `operator=` (`x = r.x; y = r.y; z = r.z;`) and copy with `*out = value`; write the select
as `float side; if (cond) { ...; side = -1.0f; } else { side = 1.0f; }`; use two `bool` members set to true for the flag pair so the
compiler merges them into one immediate store.
