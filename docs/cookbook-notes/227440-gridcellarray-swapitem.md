# 0x227440 GridCellArray::SwapItem

<!-- tags: abi/virtual, construct/allocation, method/diagnostic, method/sibling, wall/constant, wall/control-flow, wall/inlining, wall/register-schedule -->

- Function: 0x227440 GridCellArray::SwapItem
- Label: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
- Outcome: unsolved
- Cause: register-allocation
- Best score: sim 100.0, distance 2, size 188/188 (not a byte match)
- Attempts: 7

## What differed

A two-slot swap on a square grid of pointers, written as the sibling spells it: a bounds-checked element lookup that returns
a pointer or null, and a bounds-checked store that clears the slot through a virtual call when given null. The first draft was
8 bytes too big because the element address was written as pointer plus row times width plus column, which adds the
column in 64 bits after a 32-bit multiply. Indexing the array with the whole 32-bit expression (`&cells[row * width + column]`)
produced the target's 32-bit multiply-add and the exact size. What is left is only which two scratch registers hold the two
element pointers and where the null constant is materialised: the target keeps the null in one scratch register from the entry
and the first element pointer in the other, the candidate has them the other way round.

## Spellings tried that did not help

- The lookup as an early return instead of a conditional expression: identical code.
- Named locals for the two element pointers before the stores: identical code.
- The two helpers defined in the .cpp as inline members instead of in the header: identical code.
- The lookup through a local that starts null and is assigned in the if: 2.5 points worse and 2 bytes small.
- The permuter on the swap body plus both helpers (481 candidates, 72 s): no candidate better than the start.

## Spelling that fixed it

None for the register residue. The 32-bit index spelling is the part that closed the size:

```cpp
return (x < length && y < length) ? &cells[x * length + y] : nullptr;   // not: cells + x * length + y
```
