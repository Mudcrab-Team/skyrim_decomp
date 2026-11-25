# 0x152b6d0 BSCullingProcess::InitCullDescriptor

<!-- tags: construct/constructor, wall/register-schedule -->

- Function: 0x152b6d0 BSCullingProcess::InitCullDescriptor
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 62/68 aligned bytes
- Attempts: 6

## What differed

The descriptor initializer clears its pointer members and gives the render-target index and trailing flags different defaults. The closest candidate has the right size but schedules an immediate store earlier.

## Spellings tried that did not help

Value-initializing a pointer array combined several stores. Individually initializing the named fields recovered their widths. A constructor initializer list, a static initializer function and a bounded local search over independent assignments still left a scheduling difference.

## Spelling that fixed it

None.
