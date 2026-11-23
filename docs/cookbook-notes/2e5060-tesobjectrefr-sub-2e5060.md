# 0x2e5060 TESObjectREFR sub_2e5060

- Function: 0x2e5060 TESObjectREFR sub_2e5060
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: constant-folding
- Best score: 75/99 bytes matching, size 84 vs 99
- Attempts: 5

## What differed

The two flag-bit tests (two bits of one word) fold into a single mask test despite the by-value helper (rule 16), accessors and a local copy. Rule 41.

## Spellings tried that did not help

By-value TestBit helper, accessors, a local copy.

## Spelling that fixed it

none
