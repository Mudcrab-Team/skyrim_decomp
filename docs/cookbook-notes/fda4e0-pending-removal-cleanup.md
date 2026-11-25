# 0xfda4e0 BSPortalGraph::StageAlwaysRenderChildRemove

<!-- tags: abi/exception, construct/destructor -->

- Function: 0xfda4e0 BSPortalGraph::StageAlwaysRenderChildRemove
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 266/270 aligned matching bytes
- Attempts: 8

## What differed

Staging a removal inlines the retaining array append. The best object has the right function size and a different exception-state map.

## Spellings tried that did not help

A scoped allocator and an ordinary recursive count brought the body to target size. Unsigned count variants and reversing the release branch did not close the exception-state difference.

## Spelling that fixed it

None.
