# 0x14e70b0 NiNode sub_14e70b0

- Function: 0x14e70b0 NiNode sub_14e70b0
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 47/57 matching bytes
- Attempts: 9

## What differed

The target nulls the cursor on the found case and rejoins the loop test; the compiler exits directly. The shape with a static start argument matches the entry null test and the call, then diverges at the found branch. Rule 40 symptom, not tried.

## Spellings tried that did not help

Direct exit and several loop forms.

## Spelling that fixed it

none
