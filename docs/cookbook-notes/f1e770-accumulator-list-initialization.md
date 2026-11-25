# 0xf1e770 NiBackToFrontAccumulator::NiBackToFrontAccumulator

<!-- tags: construct/constructor, wall/layout -->

- Function: 0xf1e770 NiBackToFrontAccumulator::NiBackToFrontAccumulator
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: struct-layout
- Best score: 61/61 aligned matching bytes
- Attempts: 4

## What differed

Value-initializing the list as an aggregate cleared the padding after its count. The target initializes just the count and the two links.

## Spellings tried that did not help

A member-initializer list for both links and the count corrected the store widths. C++ member declaration order still caused the links to be written before the count.

## Spelling that fixed it

Give the list a constructor that initializes its count in the member-initializer list and sets its head and tail to null in the body. The enclosing accumulator can then initialize the list and the remaining members in declaration order.
