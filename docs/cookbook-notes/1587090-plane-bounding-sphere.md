# 0x1587090 BSParabolicCullingProcess::TestBaseVisibility2

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x1587090 BSParabolicCullingProcess::TestBaseVisibility2
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 45/72 aligned bytes
- Attempts: 6

## What differed

The plane contributes its center and the greater of its two extents to a temporary bounding sphere. The scalar loads, maximum and virtual call are present in the candidate. The compiler schedules the radius relative to the three center components differently.

## Spellings tried that did not help

Aggregate initialization, computing the radius in a named local, and assigning the components individually changed register allocation or store order. The tested floating-point recipes and assignment orders did not recover the target sequence.

## Spelling that fixed it

None.
