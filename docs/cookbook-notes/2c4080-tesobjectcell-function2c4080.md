# 0x2c4080 TESObjectCELL::Function2c4080

<!-- tags: abi/calling-convention, wall/control-flow, wall/flag-fold, wall/register-schedule -->

- Function: 0x2c4080 TESObjectCELL::Function2c4080
- Label: GUESS(low)
- Outcome: unsolved
- Cause: integer-width-or-cast
- Best score: 33/58 aligned bytes; candidate size 52, target size 58
- Attempts: 4

## What differed

The original handwritten candidate compares elapsed unsigned time against one of two intervals, with
an unconditional true result when the previous time is zero. Both interval references bind. The best
candidate differs in Boolean materialization, scratch-register use and a separate return path.
The complete residue is not a register-only mismatch. The placeholder and interval names remain guesses.

## Spellings tried that did not help

- A single Boolean result initialized from the selector, updated inside the nonzero-time branch, and
  returned at the end reduced the measured aligned score from 33/58 to 11/58.
- Changing that result and return type to an unsigned byte kept the score at 11/58.
- Restoring the original branch shape with a wider unsigned return reached 25/58, still below the first
  candidate. These edits do not establish the target return type.

## Spelling that fixed it

none. Stop condition: three consecutive compares without improvement over the best, after four total.
The best candidate and every compared source snapshot are retained privately. The first-pass branch
and unsigned-byte accumulator remain the best measured source; semantic equivalence is not proven.
