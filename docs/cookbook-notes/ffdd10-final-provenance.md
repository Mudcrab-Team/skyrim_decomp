# 0xffdd10 BSProceduralLightningController::GetPropertyHolder

<!-- tags: abi/virtual, method/diagnostic -->

- Function: 0xffdd10 BSProceduralLightningController::GetPropertyHolder
- Label: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
- Outcome: fixed
- Cause: other
- Best score: 67/67 code bytes exact; comparator pass
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The preserved original body already passed the native PC comparator on its first comparison. Its nested null checks, child upper-bound check and virtual geometry lookup required no body change. Four comparisons include final provenance and naming changes because those comments participate in the source digest; this was not a four-compare code-generation search. The current method name is supported by the labelled community-generated names and sibling symbol prototype; neither establishes binary identity.

## Spellings tried that did not help
No alternative body spelling was needed. The preserved guessed method name was replaced by GetPropertyHolder. The original unqualified target and child-array field labels confused the label check because this minimal declaration uses stand-in views of inherited classes.

## Spelling that fixed it
Keep the original nested checks. Qualify provenance references as NiTimeController::target and NiTArray::_data / NiTArray::_freeIdx while retaining the observed minimal declarations. Finish the Code origin lines and required MIT declaration notice before the final comparator run. The final local pass is only a candidate pending independent verification and review.
