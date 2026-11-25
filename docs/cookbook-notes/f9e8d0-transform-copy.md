# 0xf9e8d0 NiMeshParticleSystem::UpdateWorldData

<!-- tags: wall/register-schedule, construct/float, construct/vector -->

- Function: 0xf9e8d0 NiMeshParticleSystem::UpdateWorldData
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 150/150 aligned matching bytes; the candidate has two extra register transfers and fails function size
- Attempts: 6

## What differed
The function propagates a world transform into its particle-data target, applies absolute scale and dispatches the target update. Caching the target pointer across all stores removes observed reloads. A data pointer cached across the matrix copy, followed by a target-transform reference for the point and scale, restores all target bytes in alignment but leaves two extra transfers between register classes. This is a diagnostic alignment result, not a byte match.

## Spellings tried that did not help
Scalar matrix copies, aggregate matrix and point copies, component point copies, representation-preserving component copies and a single cached target pointer did not match. Repeated target reads at member boundaries improved the score to 127/150. Grouping the point and scale through one transform reference reached 150/150 with extra transfers. A one-worker bounded permutation search tested 12 candidates and kept distance 2.0 unchanged.

## Spelling that fixed it
none
