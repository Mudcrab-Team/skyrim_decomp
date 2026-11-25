# 0xfee050 BSCullingProcess::ClearCollectedGeometry

<!-- tags: construct/destructor, abi/exception -->

- Function: 0xfee050 BSCullingProcess::ClearCollectedGeometry
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 323/370 aligned matching bytes
- Attempts: 3

## What differed

Releasing all the retained geometry reached the target function size. Register saves and the loop still differ.

## Spellings tried that did not help

Replacing an indexed walk with a pointer and remaining count, and caching the referenced object before decrement, retained the unwind mismatch.

## Spelling that fixed it

None.
