# 0x6a1120 Character::IsInSitSleepTransition

- Function: 0x6a1120 Character::IsInSitSleepTransition
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: constant-folding
- Best score: first mismatch at the first field test; size mismatch
- Attempts: 10

## What differed

Reads as: sit/sleep state not in the normal, sitting or sleeping values of one packed state word. The target keeps three separate masks of the loaded word; every spelling folds them into one mask. Rule 41. Explicit base-pointer conversions with null checks, or a 16-bit truncation, kept the masks apart but added code the target lacks.

## Spellings tried that did not help

About 40 spellings: bit-fields, raw masks, shifts, signed fields, struct copies, helpers, switch, loops, base-class views.

## Spelling that fixed it

none
