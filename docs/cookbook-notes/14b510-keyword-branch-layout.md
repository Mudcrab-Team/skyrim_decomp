# 0x14b510 EffectSetting::HasKeyword

<!-- tags: abi/virtual, wall/control-flow, method/sibling -->

- Function: 0x14b510 EffectSetting::HasKeyword
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: branch-layout
- Best score: distance 4.5; 63/84 matching bytes
- Attempts: 5 counted comparisons; 5 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The qualified base keyword query and associated-form predicate compile to the same instruction count as the target, but the comparator reports a function-size mismatch. The diagnostic classifies branch polarity, ordering and register differences. The sibling is a control-flow lead, not Skyrim evidence.

## Spellings tried that did not help
Expanding the predicate into early returns measured distance 18.0. Narrowing the guessed associated-form-type declaration to a byte measured 5.0 and was reverted. A bounded search exhausted 225 candidates without improving the original distance 4.5. Replaying the original structure after restoring the field width retained 4.5; the last comparison covers the final provenance labels.

## Spelling that fixed it
None. The original nested predicate remains the best candidate, retained privately after three non-improving comparisons. No byte match is claimed.
