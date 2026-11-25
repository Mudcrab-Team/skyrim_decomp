# 0x5dc9e0 ActiveEffectReferenceEffectController::EffectShouldFaceTarget

<!-- tags: wall/control-flow, construct/bitfield, method/sibling -->

- Function: 0x5dc9e0 ActiveEffectReferenceEffectController::EffectShouldFaceTarget
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: branch-layout
- Best score: 85/85 bytes; native comparator pass
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The first body expressed the null guards as separate early returns. It reached 71/85 aligned bytes. The final body expresses the guards and the flag predicate as one short-circuit return expression. The comparison then passed with the complete 85-byte extent. Later checks reproduced the passing body after provenance comments were completed.

## Spellings tried that did not help
Separate false returns for the missing effect/base object and missing hit visuals did not match. Caching the repeated base-object lookup was not introduced; the final expression retains its separate source reads.

## Spelling that fixed it
Return the conjunction of the effect pointer, base-object pointer, hit-visuals pointer and final flag predicate. Keep the repeated accessor expressions and their order. The allowed sibling body is cited in the unit; it was a source lead, not evidence about this target.
