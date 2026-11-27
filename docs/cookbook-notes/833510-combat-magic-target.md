# 0x833510 CombatMagicCaster::GetMagicTarget

<!-- tags: abi/calling-convention, abi/virtual, wall/control-flow, wall/register-schedule -->

- Function: 0x833510 CombatMagicCaster::GetMagicTarget
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: register-allocation
- Best score: distance 3.5 (from 15 on the first draft); not a byte match
- Attempts: 5 counted comparisons in total

## What differed
The best reconstruction has 32 instructions against 31 in the target, and the comparator still reports a function-size mismatch. Shared exit lowering remains a hypothesis, consistent with cookbook rule 58; a register-only diagnosis is not established. The community method name and partial declarations were used, while the handle/pointer result representation remains a low-confidence inference.

## Spellings tried that did not help
The initial four-way assignment followed by one aggregate return measured 63/97 aligned bytes. A bounded PC permutation search scored 257 candidates and improved distance from 5.0 to 3.5 by reversing the empty-cache test on the self-delivery path; its candidate measured 79/97 in an ordinary comparison. Default-initializing either local and assigning it only on the non-default paths measured 30/97. An explicit output-reference signature with shared stores measured the same 79/97 and did not establish that signature as correct. Three comparisons after the best state did not improve it. Retrieval identified the existing shared-tail caution, but supplied no closing spelling.

- Giving both outputs an explicit value in every arm (handle and actor, with zero or null on the unused one) and no initialiser on the declarations moved the distance from 15 to 3.5; initialising at the declaration put zero stores before the virtual call and kept two extra callee-saved registers.
- Testing the handle count first in each arm matches the branch polarity but swaps the output registers (distance 5). In the target, the zero in the first arm is the delivery value that the compiler already has in the return register.

## Spelling that fixed it
None. The best spelling is the explicit-arm version; the arm order of the branches and the register of the zero remain.
