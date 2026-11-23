# 0xce3250 BSReadWriteLock::LockForRead

- Function: 0xce3250 BSReadWriteLock::LockForRead
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 63/112 aligned bytes, size equal
- Attempts: 7

## What differed

Pure callee-saved swap: this in one register and the spin counter in the other, reversed from the target. Rule 12. New in this round: noexcept and a hoisted lock-pointer local, no change.

## Spellings tried that did not help

See rule 12.

## Spelling that fixed it

none
