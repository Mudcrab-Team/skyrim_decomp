# 0xf24380 NiCollisionData::Functionf24380

<!-- tags: method/sibling, sibling/f3, construct/loop -->

- Function: 0xf24380 NiCollisionData::Functionf24380
- Label: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
- Outcome: fixed
- Cause: loop-shape
- Best score: PC comparator PASS (all checks passed)
- Attempts: 5

## What differed

The ancestor query used a distinct null-return path and recursive parent walk. Collapsing the null and name checks changed its branches.

## Spellings tried that did not help

The combined loop predicate merged paths that remain separate in the target.

## Spelling that fixed it

Use the cited sibling recursive shape with an explicit null check before the name comparison and parent recursion.
