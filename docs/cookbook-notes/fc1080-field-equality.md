# 0xfc1080 NiPSysFieldModifier::IsEqual

<!-- tags: construct/float, wall/register-schedule, wall/control-flow -->

- Function: 0xfc1080 NiPSysFieldModifier::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: operand-order
- Best score: 129/129 matching bytes; local comparator PASS
- Attempts: 4

## What differed
The first draft omitted the case where only the other field-object pointer was present. Correcting that case restored the target extent and control flow but left register allocation differences. Float comparisons use the fast floating-point recipe described by cookbook rule 48.

## Spellings tried that did not help
A compound return expression and separate early returns both measured 79/129 matching bytes before correcting the null case. The corrected null case measured 63/129 despite a much smaller alignment distance, illustrating that matching-byte counts alone do not describe structural progress.

## Spelling that fixed it
A bounded one-worker search selected a bundle: place the other object's scalar operands first, and keep the final boolean and distance comparisons in the attenuation check's else branch. The ordinary comparator passed the tidied source. The search examined 41 candidates; no isolated attribution to one mutation is claimed. Source is original from local observations with labelled community and symbol declarations; no sibling body was used. This local pass requires independent verification and review for acceptance.
