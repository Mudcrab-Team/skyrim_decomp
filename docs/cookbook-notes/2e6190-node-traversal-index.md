# 0x2e6190 NiNode::FindAddonAttachPoint

<!-- tags: construct/loop, abi/virtual, wall/callee -->

- Function: 0x2e6190 NiNode::FindAddonAttachPoint
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: integer-width-or-cast
- Best score: 156/186 matching bytes; alignment distance 6.0; 187-byte candidate extent
- Attempts: 6 counted comparisons and one binding-only failure

## What differed
The observed nullable root, child-node conversion, RTTI-parent traversal, recursive call and indexed child detachment are represented. A full-width loop counter with a narrow bound comparison improved the candidate from 124 to 156 matching bytes. The remaining discrepancy includes argument preparation at the virtual detachment call, loop-end instruction shape and one reference classification. This is not yet a register-only wall.

## Spellings tried that did not help
An instance method without a root-null guard scored 89 matching bytes. An explicit RTTI match break scored 121; an explicit typed cast result scored 90. Narrowing the index forwarded to child detachment changed the saved-register set and scored 120. The 156-byte-match source is retained. One malformed private binding-hint schema was corrected before any counted comparison.

## Spelling that fixed it
none
