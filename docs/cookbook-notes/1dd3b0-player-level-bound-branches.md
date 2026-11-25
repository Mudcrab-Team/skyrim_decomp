# 0x1dd3b0 TESActorBaseData::GetLevel

<!-- tags: construct/bitfield, construct/float, wall/control-flow, wall/register-schedule -->

- Function: 0x1dd3b0 TESActorBaseData::GetLevel
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 74/122 matching bytes; alignment distance 8.0; not a byte match
- Attempts: 4

## What differed

The function scales a stored actor level for player-relative actors, then checks optional bounds. A base-class conversion must preserve a null actor pointer. The minimum check returns immediately, while the maximum check selects a bound. The final draft has the target extent and no aligned behavior-value mismatches, but branch layout, scheduling and register choices still differ.

## Spellings tried that did not help

A fallback player level of one changed the null-input behavior. Returning the stored level before bounds checks and assigning the minimum before the maximum produced different branch structure. Modelling the base-class conversion and making the minimum an early return improved matching-byte coverage from 23 to 74. A bounded one-worker permutation search tested 81 candidates and retained distance 8.0. Cookbook rule 16 supplied the flag helper from the first draft; its isolated effect was not measured.

## Spelling that fixed it

none
