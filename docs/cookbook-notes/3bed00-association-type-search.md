# 0x3bed00 TESNPC::HasAssociationType

<!-- tags: construct/loop, wall/register-schedule, wall/inlining -->

- Function: 0x3bed00 TESNPC::HasAssociationType
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: distance 1.0 after a bounded permutation search; start 2.0
- Attempts: 3 counted comparisons

## What differed

The pointer-array search has the target's shape. The target copies the wanted type into a second register at entry, because the array end takes the first argument register; the draft keeps the type where it arrived and puts the array end in the other register, so every later use differs.

## Spellings tried that did not help

- A for loop with the end pointer declared in its header instead of a while loop.
- Moving the search into an inline member of the array type, which compiled to identical code, so an inlined helper with a by-value parameter does not force the copy here.
- Int-type, commute and and-split rewrites from the permutation search, which only moved the distance from 2.0 to 1.0.

## Spelling that fixed it

None.
