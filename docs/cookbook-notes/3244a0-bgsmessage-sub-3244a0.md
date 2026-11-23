# 0x3244a0 BGSMessage sub_3244a0

- Function: 0x3244a0 BGSMessage sub_3244a0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 55/128 bytes matching, size 141 vs 128
- Attempts: 7

## What differed

A list-node destructor: the target has an exception-state frame slot store and nops after both calls; the candidate lacks them. Rule 13. 0x395320 (BGSNote) has the same shape and was not attempted.

## Spellings tried that did not help

noexcept(false); a non-destructor form.

## Spelling that fixed it

none
