# 0xee45e0 NiStream::Functionee45e0

<!-- tags: wall/register-schedule, wall/control-flow -->

- Function: 0xee45e0 NiStream::Functionee45e0
- Label: GUESS(low)
- Outcome: fixed
- Cause: register-allocation
- Best score: local comparator PASS; full 69-byte extent covered
- Attempts: 2 counted compares; one bounded single-worker permutation search

## What differed

Two branch-local assignments of the same stream state compiled with one different base register on the path without a call. The first compare measured 59/69 aligned matching bytes, distance 0.5, with the same instruction count and bound references. This was the open scratch-register case named by cookbook rule 55.

## Spellings tried that did not help

The initial two branch-local assignments remained below a pass. A four-candidate single-worker permutation search exhausted its pool at distance 0.5 without producing a new object state.

## Spelling that fixed it

Keep the call in the first branch, return from the branch that requires no state change, then write the common state once after the conditional. The compiler still emits the target's separate paths, while the source gives both paths one assignment. The second compare passed. This is related to cookbook rules 34 and 58; the measured change closes a base-register choice in a state store rather than a result return.
