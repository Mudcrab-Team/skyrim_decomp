# 0x14e70b0 NiNode::AsBSFadeNode

- Function: 0x14e70b0 NiNode::AsBSFadeNode
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 57/57
- Attempts: 9

## What differed

The candidate exited directly when it found a node, while the target returned through the loop's common test.

## Spellings tried that did not help

A direct parent field read in a while loop, a do-while loop, and an inline helper that updated the cursor all exited directly.

## Spelling that fixed it

A for loop advanced its cursor through a small inline parent accessor, using a null cursor when the virtual query succeeded. The accessor produced a matching comparison; its original presence is unknown.
