# 0x1581e90 BSShadowDirectionalLight deleting destructor

<!-- tags: abi/exception, construct/destructor, wall/inlining -->

- Function: 0x1581e90 BSShadowDirectionalLight deleting destructor
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: other
- Best score: 370/370 bytes with the array clear inlined; eh-reference-mismatch on the first ip-to-state entry
- Attempts: 3

## What differed
With the array `Clear` out of line the draft is 349 bytes; with it inlined the code bytes match but the comparator reports that
the first ip-to-state entry does not encode the deleting destructor's own address. Sibling deleting destructors (0x155d890,
0x1587ef0) pass with the same body style.

## Spellings tried that did not help
Assigning the cascade camera pointer null versus releasing in a block; the scalar-deleting wrapper with or without the plain
destructor referenced.

## Spelling that fixed it
none. Related: 0x15121a0 and 0x1510db0 are near-misses of another kind (prologue home slots; a dead address computation of a list element).
