# 0x1460a0 AlchemyItem::CopyMagicItemData

<!-- tags: construct/bitfield, wall/register-schedule -->

- Function: 0x1460a0 AlchemyItem::CopyMagicItemData
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: operand-order
- Best score: 79/79 aligned matching bytes; PC comparator pass on final source
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The first comparison measured 72/79 aligned matching bytes with equal function sizes. Its only differences were the two owners of the form-type load and comparison. The field copies already agreed. The bounded permutation search found a comparison operand reversal at distance zero and obtained a comparator pass.

## Spellings tried that did not help

The initial condition placed the destination form type on the left of the equality. That compiled with the source byte loaded first. The search also examined condition and comparison variants; its recorded winning mutation was comparison reversal.

## Spelling that fixed it

Use `source && source->formType == formType`. This ordinary equality spelling preserves the null guard and makes the destination byte the loaded operand. The winning source was copied without other body changes and then passed the normal PC attempt. The result is a local candidate, pending independent verification and review.
