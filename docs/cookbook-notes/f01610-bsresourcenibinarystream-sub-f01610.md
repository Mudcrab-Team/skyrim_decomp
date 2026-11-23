# 0xf01610 BSResourceNiBinaryStream sub_f01610

- Function: 0xf01610 BSResourceNiBinaryStream sub_f01610
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 20 matching bytes, size 50 vs 51
- Attempts: 5

## What differed

The target computes the address of the position member once into a register before the branch and uses it for the add, the compare and the store. None of the spellings made the compiler hoist the address.

## Spellings tried that did not help

Plain member access, a reference to the member, a nested struct with an inline method, a pointer accessor.

## Spelling that fixed it

none
