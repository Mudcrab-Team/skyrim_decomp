# 0x415440 Sky::SetWeather

<!-- tags: method/diagnostic -->

- Function: 0x415440 Sky::SetWeather
- Label: GUESS(low)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 111 of 112 bytes (candidate size)
- Attempts: 5

## What differed

The last block sets or clears a flag from a weather pointer. The target returns after the set path and tests the pointer again only when the flag was already set. The candidate falls through to the second test.

## Spellings tried that did not help

One if with an else-if, two separate ifs, a local copy of the pointer, an early return, bit fields, and set and reset accessors on a flag wrapper. The accessors gave the memory form of the clear and the right load order.

## Spelling that fixed it

none
