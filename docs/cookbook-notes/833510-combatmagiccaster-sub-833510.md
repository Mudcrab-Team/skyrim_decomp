# 0x833510 CombatMagicCaster sub_833510

- Function: 0x833510 CombatMagicCaster sub_833510
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 59/97 bytes matching, size 101 vs 97
- Attempts: 6

## What differed

A two-way select with one shared store tail. The candidate allocates the value and pointer to swapped registers and duplicates a branch. Rule 34 describes the shared tail but was not recorded as tried here.

## Spellings tried that did not help

Tail-duplicated returns, locals then one store, brace-init return, zero-initialised defaults.

## Spelling that fixed it

none
