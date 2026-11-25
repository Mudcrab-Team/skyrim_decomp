# 0x1586c90 BSParabolicCullingProcess::UpdateLightPlanes

<!-- tags: construct/float, construct/constructor -->

- Function: 0x1586c90 BSParabolicCullingProcess::UpdateLightPlanes
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: 223/223 aligned matching bytes
- Attempts: 4

## What differed

Building the direction as a separate local changed when the camera rotation components were loaded.

## Spellings tried that did not help

An aggregate assignment and a separate direction local both left differences.

## Spelling that fixed it

Copy the three point components in member order and pass the direction as a braced temporary directly to the plane constructor.
