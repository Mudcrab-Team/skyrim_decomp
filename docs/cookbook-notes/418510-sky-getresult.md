# 0x418510 Sky::GetResult

- Function: 0x418510 Sky::GetResult
- Label: GUESS(low)
- Outcome: fixed
- Cause: register-allocation
- Best score: 41/41
- Attempts: 3

## What differed

The pointer chain used a different temporary register for its middle pointer.

## Spellings tried that did not help

Separate locals and early returns, including an instance method, preserved the mismatch.

## Spelling that fixed it

An instance method using a small local lambda to retrieve the next pointer and a conditional expression for the final result matched. Both changes were made together; their individual effects were not isolated.
