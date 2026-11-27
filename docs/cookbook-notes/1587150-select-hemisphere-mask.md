# 0x1587150 BSParabolicCullingProcess::GetHemisphereMask

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x1587150 BSParabolicCullingProcess::GetHemisphereMask
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 159/222 aligned matching bytes
- Attempts: 5

## What differed

The distance and side tests can have the right size and instruction shapes while using different registers throughout the mask calculation.

## Spellings tried that did not help

A search over 216 equivalent branch, return and mask expressions produced 29 distinct compiler outputs. The best variant still differed when compared as the original member.

## Spelling that fixed it

None.
