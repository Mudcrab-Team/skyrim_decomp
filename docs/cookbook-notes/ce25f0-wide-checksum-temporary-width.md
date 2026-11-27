# 0xce25f0 CRC32Calculator::SizeOf64

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0xce25f0 CRC32Calculator::SizeOf64
- Label: GUESS(low)
- Outcome: unsolved
- Cause: integer-width-or-cast
- Best score: 54/198 aligned matching bytes; structural variant distance 22
- Attempts: 5

## What differed

The checksum uses byte lookups while shifting a wider intermediate. A counted form compiled much smaller than the target. Explicit updates with a wide accumulator approached the target extent, but the temporary widths and schedule still differed. The supplied class and method names remain hypotheses.

## Spellings tried that did not help

A progressively shifted input improved the aligned-byte score to 54/198. Folding the whole input into the checksum shortened the candidate too far. A wide accumulator with fixed input shifts reached a lower weighted distance of 22. A 16-candidate permutation search did not improve that distance.

## Spelling that fixed it

none

The bounded attempt rule stopped this target. Every attempted source revision and object is retained privately; no byte-match claim is made.
