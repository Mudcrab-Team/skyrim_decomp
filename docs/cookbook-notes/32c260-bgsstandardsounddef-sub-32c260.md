# 0x32c260 BGSStandardSoundDef sub_32c260

- Function: 0x32c260 BGSStandardSoundDef sub_32c260
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 19/40 bytes matching
- Attempts: 5

## What differed

The target reuses the register that held this for the loaded parent pointer; the candidate allocates the return register. Rule 12 family (same instructions, other registers).

## Spellings tried that did not help

The result line records no specific spellings beyond ordinary reordering.

## Spelling that fixed it

none
