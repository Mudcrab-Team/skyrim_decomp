# 0x30d9b0 TESWorldSpace::Function30d9b0

<!-- tags: construct/float, wall/inlining -->

- Function: 0x30d9b0 TESWorldSpace::Function30d9b0
- Label: CRASHLOGGER_PDB(59818@2026.10.24); Function30d9b0: GUESS(low)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 87/95 matching bytes
- Attempts: 5

## What differed
The local target observations include a rounded fractional subtraction before each floor correction. The best handwritten cast-and-correct version omits both subtractions under the pinned floating-point recipe. Its branch behavior also requires the negation of a greater-or-equal comparison; a less-than comparison changes unordered handling. The generated CrashLogger layout supports the TESWorldSpace maximum-coordinate fields, but the method name remains a guess. Source exposure was local target observations and generated layout declarations; no sibling body was used.

## Spellings tried that did not help
The initial less-than branch measured 77/95. Preserving unordered behavior improved to 87/95. Standard library floor calls measured 23/95 with a size mismatch. An explicit packed conversion helper measured 16/95. Explicit scalar SIMD fractional subtraction measured 40/95 with a size mismatch. All five comparisons and source snapshots remain private; the final source restores the best draft. Three consecutive comparisons did not improve the best score. Retrieved lessons had no tags or applicable indexed entry.

## Spelling that fixed it
none. The remaining arithmetic and inlining difference needs further investigation; this is a near-miss, not a byte-match claim.
