# 0x256160 TESRegionNoiseFunction::InterpolatedNoise

<!-- tags: wall/register-schedule, construct/float, sibling/fo4 -->

- Function: 0x256160 TESRegionNoiseFunction::InterpolatedNoise
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: 297/297 (exact)
- Attempts: 9

## What differed

The calls, their order and the float maths match, but the candidate is one byte shorter (296 against
297) and the integer registers are assigned differently. The target keeps the second row index (row
plus 64) in a callee-saved register across two calls and recomputes the first column plus 64 for each
use; the candidate recomputes both. The scratch frame is identical, so the difference is only which
sums the allocator keeps.

## Spellings tried that did not help

- The row scale computed inline in the final call, or between the third and fourth corner reads: same bytes.
- A named local for the row plus 64 (before the third corner read, or at the top): same bytes.
- Named locals for both column plus 64 and row plus 64: worse (200 of 297).
- Reading the corner values in a different statement order: the scheduler produced the same code.

## Spelling that fixed it

The permuter found it (one mutation, inlining a single-use temporary): the fourth corner read is written directly as the
argument of the last-but-one interpolation instead of being held in a named float local. Written that way the allocator
keeps the row sum in the callee-saved register as the target does. Only that one temporary is inlined; the other three
corner reads stay named, and naming all of them or none of them gives the worse codes above.
