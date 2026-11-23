# 0x9ff790 Actor sub_9ff790

- Function: 0x9ff790 Actor sub_9ff790
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: calling-convention
- Best score: 53/60 bytes matching, size 59 vs 60
- Attempts: 3

## What differed

Only the register that holds the loaded vtable pointer for the virtual error-log call differs: the target uses a scratch register that is not the return register, the candidate reuses the return register. Not covered by any rule; the call form of the VM log helper is probably not what the draft assumed.

## Spellings tried that did not help

Return type bool; a variadic signature for the logging call.

## Spelling that fixed it

none
