# 0xf9c5c0 NiPSysGravityModifier::IsEqual

<!-- tags: wall/register-schedule -->

- Function: 0xf9c5c0 NiPSysGravityModifier::IsEqual
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: register-allocation
- Best score: alignment distance 3.0, 73/181 matching bytes with equal function extent; earlier precise-float draft had 150/181 matching bytes but a 195-byte extent
- Attempts: 4

## What differed
The existing fast floating-point recipe removes seven extra unordered-comparison checks and gives the target's 181-byte extent and instruction shape. The remaining difference is a partly inconsistent swap of two saved object registers, with related prologue and epilogue changes. A local comparator pass was not obtained.

## Spellings tried that did not help
Changing the scalar equality conjunction into early rejection preserved the initial extra checks under the precise recipe. Moving the typed input declaration before the base comparison did not change the residual distance. A single-worker permutation search tested 81 candidates and retained distance 3.0.

## Spelling that fixed it
none
