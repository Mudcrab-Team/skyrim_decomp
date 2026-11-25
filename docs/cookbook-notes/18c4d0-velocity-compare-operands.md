# 0x18c4d0 ExtraWaterCurrentZoneData::IsNotEqual

<!-- tags: construct/float, wall/register-schedule, wall/control-flow -->

- Function: 0x18c4d0 ExtraWaterCurrentZoneData::IsNotEqual
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: operand-order
- Best score: comparator PASS, 72/72 code bytes; initial aligned matching bytes 18/72
- Attempts: 2 counted comparisons; 2 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The first source had the same size and instruction structure but reversed the operands of all six component comparisons. Its aligned distance was 1.0. The fast floating point recipe was selected before the first comparison following cookbook rule 48; the remaining issue was operand order, as described by rule 42.

## Spellings tried that did not help
The initial spelling placed the other object's component first and returned true from the disjunction of inequalities. It compared unsuccessfully once. The bounded search retained that failed source and tested operand reversals and early-return inversions; intermediate candidates did not close the residue.

## Spelling that fixed it
Place this object's component first in each inequality and return false when the negated disjunction holds, followed by a true return. The permuter found distance zero in 73 candidates. The resulting ordinary comparisons were formatted, provenance comments completed, and the exact final source passed the unchanged PC attempt on counted comparison two. This is one-host candidate evidence, not acceptance.
