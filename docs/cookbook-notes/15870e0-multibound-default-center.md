# 0x15870e0 BSParabolicCullingProcess::TestBaseVisibility1

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x15870e0 BSParabolicCullingProcess::TestBaseVisibility1
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 78/100 aligned bytes
- Attempts: 6

## What differed

The shape fills a temporary sphere that begins with a shared default center and a zero radius. The candidate clears a floating-point register to store the radius. The target writes the zero directly to the temporary.

## Spellings tried that did not help

Aggregate initialization and explicit component assignments produced the same size mismatch. Assigning the radius first and trying alternative assignment orders did not reproduce the complete function.

## Spelling that fixed it

None.
