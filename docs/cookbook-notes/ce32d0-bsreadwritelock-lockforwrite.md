# 0xce32d0 BSReadWriteLock::LockForWrite

- Function: 0xce32d0 BSReadWriteLock::LockForWrite
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 52/126 aligned bytes
- Attempts: 10

## What differed

All body instructions agree; the candidate keeps this in one callee-saved register and the spin counter in the other, the target the reverse. Rule 12. Declaring the spin counter first hoists the zeroing (size 131, 70/126).

## Spellings tried that did not help

A non-volatile owner field, spin declared first, for loop, while(true) with break, inverted if/else, unsigned long types, ternary sleep, continue.

## Spelling that fixed it

none
