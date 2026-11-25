# 0xf97980 SplineSetLeaff97980::SetData

<!-- tags: method/sibling, sibling/fo4, abi/exception -->

- Function: 0xf97980 SplineSetLeaff97980::SetData
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 110/130 aligned bytes; both functions are 130 bytes
- Attempts: 2

## What differed
The body aligns, but the saved-register order and the entry and exit frame operations differ.

## Spellings tried that did not help
- The recovered setter and the alternative recipe without exception handling retain the same frame difference.

## Spelling that fixed it
None.
