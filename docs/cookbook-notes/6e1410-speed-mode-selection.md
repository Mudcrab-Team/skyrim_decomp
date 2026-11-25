# 0x6e1410 ActorState::GetMoveModeForMaxSpeed

<!-- tags: construct/bitfield, construct/switch, method/diagnostic, wall/constant, wall/register-schedule -->

- Function: 0x6e1410 ActorState::GetMoveModeForMaxSpeed
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 72/72 exact bytes, comparator pass
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The direct-return switch retained the cleared movement flags in the return register and combined them with each speed constant there. It also folded the initial mask into a wider immediate operation. The resulting function was shorter than the target. The body was adapted from the permitted sibling movement-mode selector; the sibling is a source lead, not target evidence.

## Spellings tried that did not help
- Direct returns from each switch arm: 4/72 aligned matching bytes.
- Constant-first casts in the mask and return expressions: unchanged at 4/72.
- A bounded permutation search: 233 candidates, distance 7 unchanged, no winner.

## Spelling that fixed it
Initialize the short movement-mode local with the mask, then intersect it with the member. Select the short speed flag in a separate local through the switch, and combine the two locals at the return. This bundle produced the exact target on comparison 3; the individual effects of its two changes were not isolated. The final provenance comments were present in that passing comparison.
