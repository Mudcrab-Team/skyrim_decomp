# 0x152b930 CullJob_SetupDeferredAppend

<!-- tags: wall/control-flow -->

- Function: 0x152b930 CullJob_SetupDeferredAppend
- Label: GUESS(low)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 237/298 aligned matching bytes
- Attempts: 2

## What differed

The job selects a process from one of two pools before dispatching the requested phase. Its pool index updates and phase branches differ.

## Spellings tried that did not help

Separating the two pool selections and wrapping each index explicitly still left a longer function.

## Spelling that fixed it

None.
