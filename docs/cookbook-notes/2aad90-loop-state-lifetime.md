# 0x2aad90 TESObjectLAND::Function2aad90

<!-- tags: construct/loop, wall/register-schedule, wall/control-flow -->

- Function: 0x2aad90 TESObjectLAND::Function2aad90
- Label: GUESS(low)
- Outcome: fixed
- Cause: register-allocation
- Best score: local comparator pass for the 60-byte function; earlier best 22/60 matching bytes, distance 4.0
- Attempts: 3 counted compares; one bounded PC permutation search

## What differed
A scan over five texture pointers had the expected behavior, but its loop setup used different registers and scheduled two operations differently. The first spelling also gave the bound comparison signed semantics.

## Spellings tried that did not help
The nested guard with a signed loop counter scored 20/60 matching bytes at distance 4.5. An unsigned counter improved this to 22/60 at distance 4.0 and removed the signedness difference. A one-worker PC search scored 241 candidates without improving distance 4.0.

## Spelling that fixed it
A bundle of ordinary source changes closed the comparison: use early returns for the quadrant and data guards, keep the loaded-data pointer in a named local, and declare the unsigned result counter before the texture cursor. Use a while loop with explicit counter and cursor advancement. These changes expose the loop state before the pointer setup; no individual change was isolated as the sole cause. This is one-host candidate evidence, pending the normal independent verification and review.
