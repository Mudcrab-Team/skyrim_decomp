# 0x387e20 TESShout::Function387e20

<!-- tags: construct/loop, wall/register-schedule, wall/control-flow -->

- Function: 0x387e20 TESShout::Function387e20
- Label: GUESS(low)
- Outcome: fixed
- Cause: register-allocation
- Best score: local comparator pass for the 54-byte function
- Attempts: 3 counted compares; one bounded PC permutation search

## What differed
A reverse scan of three variations needs separate running loop state and a result index. Cookbook rule 44 identified that distinction, but the first draft copied the result into a wide temporary each iteration. Correcting the model left one extra operation and four register-renaming differences.

## Spellings tried that did not help
The per-iteration copy scored 26/54 matching bytes at distance 5.5. Keeping a running signed 64-bit count and a separate 32-bit result reduced the distance to 3.0, with 19/54 matching bytes; declaring the cursor before the running count retained the extra operation.

## Spelling that fixed it
Declare and initialize the result index, then the running count from that index, then the variation cursor. Preserve the copied pre-decrement count for the loop continuation test. A one-worker PC permutation search found this declaration swap after 17 candidates; its comparator passed and the normal wrapper comparison confirmed the same source. Rule 44 supplied the loop model, and the declaration ordering completed it. This is one-host candidate evidence pending independent verification and review.
