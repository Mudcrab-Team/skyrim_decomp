# 0x1cbc90 TESFile::Function1cbc90

<!-- tags: wall/register-schedule -->

- Function: 0x1cbc90 TESFile::Function1cbc90
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: normalized instruction distance 1.0; comparator FAIL
- Attempts: 1

## What differed

The indexed file accessor has matching instructions and branches except the temporary register holding the decremented index.

## Spellings tried that did not help

The original indexed expression and a bounded permutation search retained the register difference. Six distinct compiled states were observed; the best normalized distance remained 1.

## Spelling that fixed it

none
