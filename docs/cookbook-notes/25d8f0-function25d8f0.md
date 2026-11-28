# 0x25d8f0 Function25d8f0

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x25d8f0 Function25d8f0
- Label: none
- Outcome: unsolved
- Cause: loop-shape
- Best score: 61/83 (aligned_matching_bytes)
- Attempts: 6

## What differed

This function iterates over a small-buffer array whose inline-storage flag selects between an embedded buffer and a heap pointer. The target checks the inline-storage flag inside the loop body on each element access, whereas the compiler hoisted the storage-pointer selection out of the loop in the candidate, producing one extra byte and a different loop body.

## Spellings tried that did not help

- Helper method returning the active data pointer called inside an indexed `for` loop.
- Inline ternary selecting inline versus heap storage inside the loop body.
- Separate union members for the inline array and heap pointer accessed through `operator[]`.
- Loop counter typed as both unsigned 32-bit integer and pointer-sized integer.

## Spelling that fixed it

none
