# 0x1586fc0 BSParabolicCullingProcess::TestSphere

<!-- tags: construct/float, wall/control-flow -->

- Function: 0x1586fc0 BSParabolicCullingProcess::TestSphere
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 189/189 aligned matching bytes
- Attempts: 4

## What differed

The light sphere and its equatorial plane use distinct radius tests. Negating the wrong floating-point comparison changes the branch.

## Spellings tried that did not help

Grouping the side check inside a nonnegative comparison left a different branch.

## Spelling that fixed it

Return early for a negative plane distance minus radius. On the remaining path test the accumulator and the side of the plane.
