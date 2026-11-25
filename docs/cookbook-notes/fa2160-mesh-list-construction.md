# 0xfa2160 MeshUpdateLeaffa2160::MeshUpdateLeaffa2160

<!-- tags: method/sibling, sibling/fo4, abi/exception -->

- Function: 0xfa2160 MeshUpdateLeaffa2160::MeshUpdateLeaffa2160
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 25/78 aligned bytes
- Attempts: 1

## What differed
The target retains exception-state bookkeeping and initializes the embedded list through an address saved on the stack. The draft initializes the same observed fields directly without that frame shape.

## Spellings tried that did not help
- Default construction of the derived object with an inline list constructor omitted the exception-state frame.

## Spelling that fixed it
None.
