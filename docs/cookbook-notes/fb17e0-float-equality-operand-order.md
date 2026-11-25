# 0xfb17e0 NiPSysGrowFadeModifier::IsEqual

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0xfb17e0 NiPSysGrowFadeModifier::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24), SYMBOLS(fo4-pdb)
- Outcome: fixed
- Cause: operand-order (with float-codegen recipe selection)
- Best score: 104/104 aligned matching bytes; local PASS
- Attempts: 4 counted comparisons, plus 25 one-worker permutation candidates

## What differed

The precise floating-point recipe added three unordered-value checks that the target did not perform. Selecting the existing fast floating-point recipe removed those checks and produced the target size, leaving a callee-saved register exchange. The pinned target is sse-steam-1-7-104. Names and declarations came from the labelled community and symbol sources; behavior came from private target observations. No sibling body was read or adapted. These observations establish a local candidate only.

## Spellings tried that did not help

Separate inequality early returns and a combined positive equality expression both retained the extra float checks under the precise recipe. Changing only the recipe left the comparison operands in the opposite source order and did not pass.

## Spelling that fixed it

Use `reconstruction/recipes/o2-fpfast.json` as in cookbook rule 48, then place the current object's members on the left of each equality and the other object's members on the right. The one-worker permutation search found this ordinary commutation with distance zero; the fourth normal comparison confirmed a local PASS. The full equality chain keeps the observed field order.
