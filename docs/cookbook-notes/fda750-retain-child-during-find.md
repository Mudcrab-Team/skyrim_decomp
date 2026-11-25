# 0xfda750 BSPortalGraph::CommitAlwaysRenderChildAdd

<!-- tags: construct/loop, construct/destructor -->

- Function: 0xfda750 BSPortalGraph::CommitAlwaysRenderChildAdd
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 192/276 aligned matching bytes
- Attempts: 1

## What differed

Committing the addition retains the current child while scanning the live array and may append it after the scan. The candidate saves registers and arranges cleanup differently.

## Spellings tried that did not help

A scoped reference per iteration and a scoped allocator around append still left a larger function.

## Spelling that fixed it

None.
