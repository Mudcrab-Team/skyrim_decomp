# 0xfa1b60 MeshNamedCtorLeaffa1b60::MeshNamedCtorLeaffa1b60

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xfa1b60 MeshNamedCtorLeaffa1b60::MeshNamedCtorLeaffa1b60
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 80/115 aligned bytes
- Attempts: 1

## What differed
The target saves the embedded-list address in a stack slot and writes its fields in a different order. The draft initializes the observed fields directly.

## Spellings tried that did not help
- An inline list constructor did not reproduce the address temporary or store order.

## Spelling that fixed it
None.
