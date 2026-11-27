# 0x1521440 BSShaderAccumulator::UpdateSunOcclusionTestResult

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x1521440 BSShaderAccumulator::UpdateSunOcclusionTestResult
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 124/161 aligned bytes (40/40 instructions)
- Attempts: 8

## What differed

Changing the index parameter from `int` to `unsigned int` matched the entire first half of the function through the occlusion query poll and `-1` early exit. After the poll, the target computes the `sunOcclusionTests[index]` element index before testing whether the pixel count is zero, which shifts the clamp constant into a different scratch register.

## Spellings tried that did not help

- Separate `if (pixels == 0) { ... = 1.0f; } else { ... }` branches with `unsigned int index`.
- Single-expression ternary assignment `sunOcclusionTests[index].percentOccluded = (pixels == 0) ? 1.0f : ...`.
- Local `float occlusion = 1.0f` written once after the branch (added two instructions).

## Spelling that fixed it

none
