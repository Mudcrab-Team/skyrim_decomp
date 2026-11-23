# 0xf62740 NiColorInterpolator sub_f62740

- Function: 0xf62740 NiColorInterpolator sub_f62740
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 42/61 bytes matching
- Attempts: 4

## What differed

The target loads the 16-byte colour before storing the vtable pointer and stores it before the zero fields; the compiler schedules the load late in the candidate. Rule 42 (and rule 31, sub-object construction, was not recorded as tried).

## Spellings tried that did not help

Initialiser list, body assignment, a mix of both.

## Spelling that fixed it

none
