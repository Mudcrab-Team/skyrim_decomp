# 0x833510 CombatMagicCaster::GetMagicTarget

<!-- tags: abi/calling-convention, abi/virtual, wall/control-flow, wall/register-schedule -->

- Function: 0x833510 CombatMagicCaster::GetMagicTarget
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 79/97 aligned bytes; distance 3.5; not a byte match
- Attempts: 5 counted comparisons; 5 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The best reconstruction has 32 instructions against 31 in the target, and the comparator still reports a function-size mismatch. Shared exit lowering remains a hypothesis, consistent with cookbook rule 58; a register-only diagnosis is not established. The community method name and partial declarations were used, while the handle/pointer result representation remains a low-confidence inference.

## Spellings tried that did not help
The initial four-way assignment followed by one aggregate return measured 63/97 aligned bytes. A bounded PC permutation search scored 257 candidates and improved distance from 5.0 to 3.5 by reversing the empty-cache test on the self-delivery path; its candidate measured 79/97 in an ordinary comparison. Default-initializing either local and assigning it only on the non-default paths measured 30/97. An explicit output-reference signature with shared stores measured the same 79/97 and did not establish that signature as correct. Three comparisons after the best state did not improve it. Retrieval identified the existing shared-tail caution, but supplied no closing spelling.

## Spelling that fixed it
none
