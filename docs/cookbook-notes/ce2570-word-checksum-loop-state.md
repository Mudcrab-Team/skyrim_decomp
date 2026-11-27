# 0xce2570 Functionce2570

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0xce2570 Functionce2570
- Label: GUESS(low)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 68/110 aligned matching bytes; distance 11.5
- Attempts: 5

## What differed

The candidate computes a table-based checksum of a four-byte word. A counted byte loop produced 25/110 aligned matching bytes. Explicit byte updates improved the score to 68/110 with the same function extent, but integer temporary widths and scheduling remained different. The supplied owner name is unresolved; this note makes no class-identity claim.

## Spellings tried that did not help

Advancing the input word between updates reduced matching bytes. A widened remaining-input temporary reduced them further. An inline byte-update helper returned to the earlier best score without closing the comparison. A bounded single-worker permutation search exhausted 16 candidates without improving its initial distance.

## Spelling that fixed it

none

Three consecutive comparisons failed to improve the best score. The second attempt's source was restored, and all attempts and the permutation result were retained privately.
