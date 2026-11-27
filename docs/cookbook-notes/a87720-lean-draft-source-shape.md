# 0xa87720 Unka87720::Functiona87720

<!-- tags: method/diagnostic -->

- Function: 0xa87720 Unka87720::Functiona87720
- Label: GUESS(low)
- Outcome: fixed
- Cause: calling-convention
- Best score: 8/8 aligned bytes; local comparator PASS
- Attempts: 2 verifier invocations, 2 counted; permutation candidates are separate

## What differed

The first declaration returned a full-width integer for an observed predicate. The comparison did not pass even where aligned matching-byte counts covered the target extent.

## Spellings tried that did not help

Retaining the wider return type left the extent or result materialization different.

## Spelling that fixed it

Declare the result as bool. The body predicate stays the same and the complete normal comparison passes. This qualifies the width hypothesis in cookbook rule 66: the successful direction here is toward a narrow predicate result.

This is first-host candidate evidence; a second host, independent review and integration remain required.
