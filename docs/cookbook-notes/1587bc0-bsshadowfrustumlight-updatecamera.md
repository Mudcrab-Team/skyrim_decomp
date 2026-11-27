# 0x1587bc0 BSShadowFrustumLight::UpdateCamera

<!-- tags: method/diagnostic, wall/register-schedule -->

- Function: 0x1587bc0 BSShadowFrustumLight::UpdateCamera
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 800/805 size, distance 13
- Attempts: 6

## What differed

The camera refresh for a frustum light matches in structure. The target keeps the light pointer in the first argument register and the cull value in the fifth, and loads all four light fields before the visibility branch; the candidate sinks three of the loads into the branch and keeps the cull value in the second argument register.

## Spellings tried that did not help

Hoisting the loads into named locals moved one load before the branch. A point copy of the light centre made the code larger. A separate local for the cull value shrank the code and lost bytes (792/805 on a retry). One permuter run kept the same distance.

## Spelling that fixed it

None.
