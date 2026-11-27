# 0xead5a0 PathCleanupLeafead5a0::RemoveSlashDotSlash

<!-- tags: method/sibling, sibling/fo4, method/diagnostic -->

- Function: 0xead5a0 PathCleanupLeafead5a0::RemoveSlashDotSlash
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: other
- Best score: 90/90 aligned bytes
- Attempts: 2

## What differed
The target constructs its short search pattern in a stack local. A string literal caused references to read-only storage instead.

## Spellings tried that did not help
- Passing the literal directly matched 68/90 aligned bytes.

## Spelling that fixed it
A local character array initialized with the search pattern matched the observed storage and call sequence.
