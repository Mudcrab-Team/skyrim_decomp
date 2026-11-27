# 0xce0c10 array capacity helper dispatch

<!-- tags: abi/virtual, construct/allocation, wall/register-schedule -->

- Function: 0xce0c10 array capacity helper dispatch
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: aligned distance 1; 121/127 matching bytes
- Attempts: 1

## What differed
The capacity branches, calls and extent agree. The zero-capacity cleanup dispatch uses a different scratch register in two instructions.

## Spellings tried that did not help
The bounded source search scored 129 candidates and 15 distinct compiled objects; the best distance remained one.

## Spelling that fixed it
No passing spelling was found. The source and search history remain private. A source mutation that merely compiles, or a register-only difference, does not satisfy the comparator.
