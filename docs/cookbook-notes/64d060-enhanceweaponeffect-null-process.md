# 0x64d060 EnhanceWeaponEffect::ClearTargetImpl

<!-- tags: wall/control-flow, wall/inlining, method/sibling, sibling/fo4 -->

- Function: 0x64d060 EnhanceWeaponEffect::ClearTargetImpl
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 61/69 aligned matching bytes; distance 3; candidate 65 bytes, target 69; comparator FAIL
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The candidate folds the absent target and absent actor paths directly into the final cleanup. The target instead joins those paths into a null process value and then tests that value. Calls, accessed member offsets and the event-sink adjustment agree in the local analysis, but the size and branch layout differ. The permitted sibling supplied a body and naming lead; it is not Skyrim evidence. This repeats the unresolved cause in cookbook rules 40 and 58.

## Spellings tried that did not help
- Preserved draft: initialize the process to null, then assign it inside nested target and actor checks. The first comparison measured 61/69 matching bytes.
- Leave the process uninitialized and assign it in both branches of a combined target and actor check: unchanged at 61/69.
- A local immediately invoked lambda returning the nullable process: unchanged at 61/69.
- Two conditional expressions, first selecting the actor and then its process: unchanged at 61/69.

## Spelling that fixed it
None. Three consecutive comparisons without improvement ended drafting. The final source and every attempted source are retained privately. The residue changes control flow and instruction count, so it is not a register or scheduling-only near-miss and no permutation search was indicated. This source is withheld from the passing-source set; no acceptance claim is made.
