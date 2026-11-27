# 0x1560ae0 RenderPassImmediately_Standard

<!-- tags: abi/virtual, construct/bitfield, method/binding -->

- Function: 0x1560ae0 RenderPassImmediately_Standard
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 410/410 aligned bytes
- Attempts: 9

## What differed

The skin draw context receives a shader interface from a secondary base and splits one LOD byte into a flag and an index. The first draft tested the base conversion with a branch and masked the index differently.

## Spellings tried that did not help

Aggregate initialization with a mask retaining the low seven bits changed the emitted setup. Giving the renderer a global binding from an earlier unequal draft also left two references unresolved against the right object.

## Spelling that fixed it

Name the secondary interface before assigning the context fields. Widen the LOD byte, extract its high bit and clear that single bit for the index. The same code passed in the immediate path and when expanded into the main draw routine after the renderer binding was checked.
