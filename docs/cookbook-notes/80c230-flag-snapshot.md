# 0x80c230 CombatProjectileAimController::sub_14075D1B0

<!-- tags: construct/float, construct/bitfield, wall/flag-fold, wall/register-schedule -->

- Function: 0x80c230 CombatProjectileAimController::sub_14075D1B0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: minimum distance 8.5; that candidate has 34/90 matching bytes
- Attempts: 6 counted comparisons; 7 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The flag update and scalar aim update remained a size mismatch. The retained minimum-distance candidate has 15 instructions against the target's 16; the diagnostic also classifies register and ordering differences. One other spelling had 39/90 matching bytes but a worse distance of 15.5.

## Spellings tried that did not help
The original member flag updates measured distance 12.5. Sequential compound coordinate updates measured 15.5. Snapshotting the flag word and storing it once at the end improved the distance to 8.5. Reading the timestamp first measured 11.5; publishing the intermediate flag snapshot measured 12.5. A bounded search exhausted its pool after 73 candidates without improving 8.5.

## Spelling that fixed it
None. The final source restores the minimum-distance snapshot spelling and remains a failed local candidate at the six-comparison cap. It is retained privately for follow-up.
