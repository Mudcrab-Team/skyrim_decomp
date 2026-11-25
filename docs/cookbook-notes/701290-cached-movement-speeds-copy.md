# 0x701290 ActorProcess::GetCachedMovementSpeeds

<!-- tags: construct/loop, construct/float, wall/inlining, method/diagnostic -->

- Function: 0x701290 ActorProcess::GetCachedMovementSpeeds
- Label: SYMBOLS(tesv-2013-map) SYMBOLS(fo4-pdb)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 1/86 aligned matching bytes; distance 23; candidate 63 bytes, target 86 bytes
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The target copies five pairs through a counted loop and then copies the trailing scalar. The ordinary aggregate assignment uses wider copies and has a different size. Field offsets follow the community layout; the permitted sibling body was inspected only as a shape lead and was not adapted.

## Spellings tried that did not help

- Direct aggregate assignment and assignment through a named source reference: wider copies, distance 23.
- A loop with one memory copy per scalar: unrolled into 130 bytes, distance 30.5.
- A pair element with a memberwise assignment operator: the generated array assignment still unrolled, distance 30.5.

## Spelling that fixed it

None. Stopped after three consecutive comparisons without improved aligned matching bytes. The best ordinary aggregate spelling remains private; no byte match is claimed.
