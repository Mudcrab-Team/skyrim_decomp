# 0x4aa240 BSTempEffect sub_4aa240

- Function: 0x4aa240 BSTempEffect sub_4aa240
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 41/62 bytes matching
- Attempts: 3

## What differed

The target keeps an exception-state slot and a handler around the base-class constructor call; the candidate has neither. The unit used a guessed derived class. Rule 13 territory (EH state with no source cause found).

## Spellings tried that did not help

Adding members that have destructors did not create the handler.

## Spelling that fixed it

none
