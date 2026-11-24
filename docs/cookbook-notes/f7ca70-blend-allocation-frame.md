# 0xf7ca70 BoolBlendCreateLeaff7ca70::CreateBlendInterpolator

<!-- tags: method/sibling, sibling/fo4, abi/exception -->

- Function: 0xf7ca70 BoolBlendCreateLeaff7ca70::CreateBlendInterpolator
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 99-byte candidate for a 117-byte target; distance 12
- Attempts: 2

## What differed
The recovered allocation helper omits instructions present in the target frame and uses a different argument setup.

## Spellings tried that did not help
- The recovered body and the fresh binding retry retain the size mismatch. No passing spelling was recovered.

## Spelling that fixed it
None.
