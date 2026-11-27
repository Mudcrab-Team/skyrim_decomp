# 0x1b4d80 BSSpinLock::Lock

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0x1b4d80 BSSpinLock::Lock
- Label: GUESS(low)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 62/200 aligned matching bytes
- Attempts: 6

## What differed

The recursive path and the acquisition phases were present, but the compiler collapsed acquisition conditions that remain materialized in the target. The closest variants still had a shorter control-flow body. The allowed community body supplied the starting locking idiom; the observed pause and yield phases required adaptation.

## Spellings tried that did not help

A direct interlocked helper, a Boolean acquisition helper and an atomic counter declaration did not close the comparison. Splitting the pause, zero-delay yield and delayed yield phases changed the extent and score. Reusing a wide acquisition result reduced the score on the final attempt.

## Spelling that fixed it

none

The bounded attempt rule stopped this target. Every attempted source revision and object is retained privately; no byte-match claim is made.
