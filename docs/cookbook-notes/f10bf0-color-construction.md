# 0xf10bf0 ColorExtraCtorLeaff10bf0::ColorExtraCtorLeaff10bf0

<!-- tags: method/sibling, sibling/fo4, construct/float -->

- Function: 0xf10bf0 ColorExtraCtorLeaff10bf0::ColorExtraCtorLeaff10bf0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 35/101 aligned bytes
- Attempts: 1

## What differed
The target preserves an intermediate zero-initialized color and uses vector registers and a stack temporary while copying its components. The optimizer simplified the draft into direct scalar stores.

## Spellings tried that did not help
- Zero-initializing the fields and then assigning the components compiled to a shorter sequence.

## Spelling that fixed it
None.
