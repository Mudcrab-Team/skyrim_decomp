# 0x73c5c0 HighActorCuller::ProcessActor

<!-- tags: construct/bitfield, wall/control-flow -->

- Function: 0x73c5c0 HighActorCuller::ProcessActor
- Label: GUESS(low)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 205/338 aligned matching bytes
- Attempts: 1

## What differed

The actor update combines visibility flags from the node, its fade, and a sphere test. The candidate combines several branches and has a shorter body.

## Spellings tried that did not help

An explicit result mask and a local copy of the sphere before the multibound test did not recover the flag-update sequence.

## Spelling that fixed it

None.
