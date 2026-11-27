# 0x1554d20 ImageSpaceEffect::dtor_deleting

<!-- tags: method/diagnostic -->

- Function: 0x1554d20 ImageSpaceEffect::dtor_deleting
- Label: GUESS(low)
- Outcome: fixed
- Cause: branch-layout
- Best score: 361/361
- Attempts: 4

## What differed

A loop over a pointer array that deletes each element and clears the slot was four bytes long. The loop condition read the array size before the counter increment and narrowed it twice.

## Spellings tried that did not help

Different counter types, a size accessor with either width, and a separate remove method that called the set routine with a null value.

## Spelling that fixed it

Give the array set routine the usual Gamebryo parameter shape: an unsigned index and the element by const reference. The size is then read once, after the increment.
