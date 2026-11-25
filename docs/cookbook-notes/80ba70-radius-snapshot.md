# 0x80ba70 CombatProjectileAimController::IsWithinAimRadius

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0x80ba70 CombatProjectileAimController::IsWithinAimRadius
- Label: GUESS(low)
- Outcome: fixed
- Cause: register-allocation
- Best score: comparator pass; previous distance 2.0 with 12/85 matching bytes
- Attempts: 2 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The complete distance predicate had a register-renaming residue. A bounded search found that the radius snapshot's position changed allocation of the scalar distance temporaries.

## Spellings tried that did not help
Keeping a separate controller pointer and computing the radius after all three coordinate differences left distance 2.0. The first search was rejected by source lint before compiling candidates.

## Spelling that fixed it
Read the radius through the controller directly, and compute its local value before the coordinate differences. A split declaration and assignment retained the exact candidate. The bounded search reached distance zero after 33 candidates; the unchanged comparator then passed the final source. This is a local candidate result, not acceptance.
