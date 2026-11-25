# 0x5dc6e0 ActiveEffectReferenceEffectController::GetScale

<!-- tags: construct/bitfield, wall/flag-fold, wall/control-flow -->

- Function: 0x5dc6e0 ActiveEffectReferenceEffectController::GetScale
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 77/77 code bytes; native Windows comparator PASS, unwind covered
- Attempts: 5 counted comparisons; 5 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
Testing the shifted and masked unsigned flags directly in the branch produced a shorter function and scored 69/77 matching bytes. The target's intermediate Boolean test was missing. The call sequence, accessed fields and default scale were already consistent.

## Spellings tried that did not help

- Directly branching on `(effect->flags >> 12) & 1`: 76-byte candidate for the 77-byte target, comparator FAIL.

## Spelling that fixed it
Assign the shifted and masked flag to `const bool dualCast`, then branch on that local. The second comparison passed all checks with the default recipe. This refines cookbook rule 38's width-sensitive bit tests. The allowed anonymous sibling provided the named Boolean shape; the initial indexed lesson retrieval returned no tags or applicable entries. The function remains a local candidate pending independent acceptance.
