# 0x186670 ExtraCollisionData sub_186670

- Function: 0x186670 ExtraCollisionData sub_186670
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 32/37 bytes matching, size 36 vs 37
- Attempts: 4

## What differed

A not-equal pointer compare: the target returns from the both-null path with a bare return and shares one true-return block at the end; every shape tried emits a set-on-condition, a duplicated true block or an extra jump. Rule 43.

## Spellings tried that did not help

See rule 43.

## Spelling that fixed it

none
