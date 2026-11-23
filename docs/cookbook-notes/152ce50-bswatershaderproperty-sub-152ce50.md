# 0x152ce50 BSWaterShaderProperty sub_152ce50

- Function: 0x152ce50 BSWaterShaderProperty sub_152ce50
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: branch-layout
- Best score: 62/98 bytes matching
- Attempts: 5

## What differed

A nested form tail-calls the third visitor call; the per-step null check form matches the first call but re-tests the material. The target re-reads the material unchecked and shares a non-tail exit. Rule 46.

## Spellings tried that did not help

Nested form and per-step null-check form.

## Spelling that fixed it

none
