# 0x14dba0 EnchantmentItem::InitializeData

<!-- tags: construct/float, wall/register-schedule, wall/constant -->

- Function: 0x14dba0 EnchantmentItem::InitializeData
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: instruction-order
- Best score: 83/83 code bytes validated: 79 exact and 4 by reference; comparator pass
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The first draft combined the adjacent spell-type and charge-time initializations into one wider store. The target keeps separate stores. The initial comparison measured 67/83 matching bytes and distance 3.0. Layout, constants and the base initialization call were already bound.

The body uses the permitted sibling initialization as a source lead, with its per-file citation retained. The sibling is not evidence about this build. These results are from one native Windows verifier and remain candidates pending the normal independent comparison and review.

## Spellings tried that did not help
- Writing the assignments in the observed store order: the adjacent fields still merged.
- Moving that same sequence into a small inline data-reset member, following cookbook rule 31: 67/83 matching bytes and distance 3.0 again.

## Spelling that fixed it
Assign cost, charge, spell type, casting type and delivery first, then clear flags, charge time and the two pointers, followed by the base initialization call. This ordinary default-state grouping kept the separate member stores and passed comparison 3. No recipe or binding change was involved.
