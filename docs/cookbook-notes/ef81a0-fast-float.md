# 0xef81a0 NiTimeController::IsEqual

<!-- tags: construct/float, wall/flag-fold -->

- Function: 0xef81a0 NiTimeController::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: local PASS, 126/126 code bytes
- Attempts: 3

## What differed
The ordinary float comparisons under the default precise floating-point recipe added unordered-value checks. The candidate was eight bytes longer than the target.

## Spellings tried that did not help
The initial conjunction of inequality checks used the default recipe and failed the size check.

## Spelling that fixed it
Keep the ordinary comparisons and name the existing `reconstruction/recipes/o2-fpfast.json` recipe in the unit. The second local comparison passed; the third confirmed the final declaration and label cleanup. This records compiler behavior for this build and does not establish behavior for unordered inputs independently.
