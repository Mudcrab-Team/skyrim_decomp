# 0x1588590 BSShadowParabolicLight::UpdateCamera

<!-- tags: construct/float, construct/vector, wall/register-schedule -->

- Function: 0x1588590 BSShadowParabolicLight::UpdateCamera
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 818/822
- Attempts: 10

## What differed

The dual-paraboloid camera refresh matches in structure after the work below. What remains is register choice: the target keeps the light pointer in the fifth integer scratch register where the draft uses the third, and holds the faded value in the fourth float register while the draft holds it in the second. Size is four bytes short because of the register prefix.

## Spellings tried that did not help

- Scene graph lookups as named locals for both accumulators: same bytes as the plain statements.
- An accumulator pointer local reused for both statements: same bytes.
- One permuter run reached distance 4 (draft 6.5) by declaring dy, dz, dx in that order and moving the squared-distance expression inside the fade test, but the target computes it before that test, so it was not taken.

## Spelling that fixed it

none. Pieces that closed other gaps: a scalar `-` on three elements of a copied 3x3 matrix compiles to the same shuffle and sign-mask sequence as the target when the three negated values are read into locals first (in the order 7, 4, 1) and then written back (1, 4, 7); a sphere constructor that assigns the centre member-wise (not as a block copy) gives three scalar copies; the first scene graph lookup must be its own local while the second is a plain local expression re-read after the first store, which fixed the evaluation order of the right-hand side.
