# 0x306520 TESWaterForm::InitializeData

<!-- tags: method/diagnostic -->

- Function: 0x306520 TESWaterForm::InitializeData
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 173/173
- Attempts: 7

## What differed

A copy of one three-float vector to another was scheduled differently: one store of the source vector moved after the first copy store.

## Spellings tried that did not help

Structure assignment, member-wise assignment, a user assignment operator, a constructor temporary, a set method and a chained assignment.

## Spelling that fixed it

Copy the three components in a counted loop through an index operator on the vector type.
