# 0xf69370 BoolBlendCreateLeaff69370::CreateBlendInterpolator

<!-- tags: method/sibling, sibling/fo4, abi/exception -->

- Function: 0xf69370 BoolBlendCreateLeaff69370::CreateBlendInterpolator
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 54/117 aligned bytes
- Attempts: 1

## What differed
The target retains exception-state bookkeeping and a temporary around allocation and construction. The placement-new draft emits a different frame and branch layout.

## Spellings tried that did not help
- Explicit allocator readiness, allocation and conditional placement construction did not reproduce the target frame.

## Spelling that fixed it
None.
