# 0x3a9420 BGSScene sub_3a9420

- Function: 0x3a9420 BGSScene sub_3a9420
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 128/128 bytes at best, distance 6.5
- Attempts: 6

## What differed

The target increments the iterator after the calls and keeps it in one callee-saved register; the candidate increments early and swaps two registers. Pointer-loop forms became a counted loop (rule 20). A flag-bit pair needed bitfield stand-in members to avoid a merged mask test.

## Spellings tried that did not help

Pointer loops with ++; several increment positions.

## Spelling that fixed it

none
