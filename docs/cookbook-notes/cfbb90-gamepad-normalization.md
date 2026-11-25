# 0xcfbb90 BSGamepadDevice::ProcessRawInput

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0xcfbb90 BSGamepadDevice::ProcessRawInput
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 57/78 aligned matching bytes; final restored source reproduced 57/78
- Attempts: 5 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

Scalar conversion and conditional saturation produced a larger function than the target. SIMD conversion and scalar saturation reached the target extent, but retained register and scheduling differences. No comparator pass was obtained.

## Spellings tried that did not help

- Scalar conversion followed by lower and upper conditional expressions: 57/78, candidate size 94 versus target size 78.
- Explicit scalar-vector construction and saturation: 1/78 and 6/78 in the preserved interrupted history.
- Explicit integer-vector conversion and scalar saturation: 6/78, equal extent, distance 5.5, with register and instruction-order differences.
- Bounded PC permutation search on the equal-extent spelling: 27 candidates, distance 5.5 unchanged.
- Restoring the best scalar spelling with final provenance: 57/78.

## Spelling that fixed it

none. The stop rule was reached; the failed sources and diagnostics remain private. The scalar best preserves the more readable spelling while the equal-extent SIMD state is available for future scheduling work.
