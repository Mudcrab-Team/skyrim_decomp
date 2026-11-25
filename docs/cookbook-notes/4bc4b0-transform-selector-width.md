# 0x4bc4b0 NavMesh::Function4bc4b0

<!-- tags: abi/calling-convention -->

- Function: 0x4bc4b0 NavMesh::Function4bc4b0
- Label: GUESS(low)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: full native comparator PASS
- Attempts: 2

## What differed
The transform helper received a byte-sized boolean where its call site supplies a full-width integer selector.

## Spellings tried that did not help
The boolean declaration reproduced the rest of the function but left the selector setup shorter.

## Spelling that fixed it
Declare the selector parameter as unsigned and retain the value one at the call site.
