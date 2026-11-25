# 0x64d290 EnhanceWeaponEffect::Revert

<!-- tags: wall/control-flow, wall/inlining, method/sibling, sibling/fo4 -->

- Function: 0x64d290 EnhanceWeaponEffect::Revert
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 64/72 aligned matching bytes; distance 3; candidate 68 bytes, target 72; comparator FAIL
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
After the base revert call, the target joins the absent target and absent actor paths into a null process value and tests it before unregistering the inventory event sink. The candidate folds those paths directly into the exit. The local comparison therefore has a different branch layout and instruction count. The permitted sibling supplied body and naming leads, never Skyrim evidence. This is another measured instance of the unresolved cause in cookbook rules 40 and 58.

## Spellings tried that did not help
- Assign the process in both branches of a combined target and actor check: 64/72 aligned matching bytes.
- An immediately invoked lambda returning the nullable process: unchanged at 64/72.
- Early returns for an absent target or actor: unchanged at 64/72.
- Two conditional expressions selecting the actor and its process: unchanged at 64/72.

## Spelling that fixed it
None. Three consecutive comparisons without improvement ended drafting. All failed sources and reports remain private, and the final files are withheld from the passing-source set. The mismatch changes control flow and instruction count; it is not solely register choice or scheduling and did not indicate a permutation search. No acceptance claim is made.
