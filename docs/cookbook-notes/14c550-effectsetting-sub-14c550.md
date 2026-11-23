# 0x14c550 EffectSetting sub_14c550

- Function: 0x14c550 EffectSetting sub_14c550
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 55/128 bytes matching
- Attempts: 4

## What differed

The linked-list node destructor shape is reproduced but the target has an EH state slot, nops after the two calls and a shared epilogue. Rule 13. The scalar-deleting variant also needed a CI hash line.

## Spellings tried that did not help

noexcept(false); a scalar-deleting variant.

## Spelling that fixed it

none
