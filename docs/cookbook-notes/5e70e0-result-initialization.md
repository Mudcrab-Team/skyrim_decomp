# 0x5e70e0 ValueModifierEffect::IsZeroDurationException

<!-- tags: abi/virtual, construct/switch, wall/register-schedule -->

- Function: 0x5e70e0 ValueModifierEffect::IsZeroDurationException
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: 76/76 aligned matching bytes, comparator pass
- Attempts: 5

## What differed

The initial arithmetic predicate reached 64/76 aligned matching bytes. A switch for the two accepted spell types reached 67/76, leaving only the scratch register used for the second virtual call different. This extends cookbook rule 34 to this predicate.

## Spellings tried that did not help

A result initialized to true and cleared on failure retained 67/76. Giving both virtual methods their community enum return types with that result shape fell to 57/76. Two bounded permutation searches made no improvement: 73 candidates on the arithmetic form, then 16 on the switch form.

## Spelling that fixed it

Keep the enum return types, initialize one result to false, assign true in the enchanting or concentration branch and in each accepted switch case, then return the result once. That form passed the fifth PC comparison. The flag test uses the by-value bit-index helper from rule 16. The generic helper was authored from that rule; an origin-check similarity hit does not indicate an inspected or adapted sibling helper.
