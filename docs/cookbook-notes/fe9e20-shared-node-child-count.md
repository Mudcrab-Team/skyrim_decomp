# 0xfe9e20 BSPortalSharedNode::OnVisible

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0xfe9e20 BSPortalSharedNode::OnVisible
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: branch-layout
- Best score: 217/217 aligned matching bytes
- Attempts: 5 comparisons, first local pass on comparison 2

## What differed

Testing the child count as a Boolean produced the expected length and traversal. The first conditional branch used an equality test.

## Spellings tried that did not help

A truth-value test on the unsigned short count preserved the loop and frustum restoration but left the entry branch different.

## Spelling that fixed it

Use an explicit positive-count comparison before selecting the active frustum. Take the child limit once before the loop and restore the previous frustum afterward.
