# 0x151a00 MagicItem::GetCostliestEffectItem

<!-- tags: abi/exception, construct/loop, wall/control-flow -->

- Function: 0x151a00 MagicItem::GetCostliestEffectItem
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 48/143 aligned bytes
- Attempts: 2

## What differed
The visitor object and effect-array traversal are present, but the candidate is 159 bytes for a 143-byte target range. The comparison identifies differences in exception-frame setup, registers, and call setup. This is not byte-match evidence.

## Spellings tried that did not help
A stack visitor with an inline default destructor and a virtual visit declaration retained the size difference. The diagnostic points to cookbook rule 13; the target has an exception-state slot without the corresponding handler shape. No flag sweep or artificial cleanup was added. A final provenance-only compare retained 48/143.

## Spelling that fixed it
none
