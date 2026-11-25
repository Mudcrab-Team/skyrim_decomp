# 0x5e7980 ValueModifierEffect::Function5e7980

<!-- tags: construct/switch, abi/virtual, wall/control-flow -->

- Function: 0x5e7980 ValueModifierEffect::Function5e7980
- Label: GUESS(low)
- Outcome: fixed
- Cause: switch-lowering
- Best score: 85/85 aligned matching bytes
- Attempts: 3

## What differed
A predicate selects between a constant result, an actor state bit and a virtual actor predicate. Grouping the two virtual-predicate cases in one disjunction changed the comparison order and branch layout; the first candidate measured 62/85 aligned matching bytes.

## Spellings tried that did not help
An early grouped disjunction followed by a separate single-value test preserved the behavior but did not match.

## Spelling that fixed it
A switch on the original 32-bit member, with the two virtual cases sharing a return, the state-bit case returning directly and an explicit constant default, matched on the next comparison. The method name remains provisional; the match does not establish its semantic name.

A third comparison confirmed the final attribution-comment digest after the first PASS.
