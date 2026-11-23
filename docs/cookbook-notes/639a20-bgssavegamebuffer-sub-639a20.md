# 0x639a20 BGSSaveGameBuffer sub_639a20

- Function: 0x639a20 BGSSaveGameBuffer sub_639a20
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 70/84 bytes matching
- Attempts: 9

## What differed

The target stores the stack argument before the pointed-to temporary; the candidate stores them in the reverse order. Rule 42.

## Spellings tried that did not help

const and non-const local, a reference parameter, a hoisted declaration.

## Spelling that fixed it

none
