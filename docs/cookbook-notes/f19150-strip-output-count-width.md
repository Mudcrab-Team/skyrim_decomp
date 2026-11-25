# 0xf19150 NiTriStripsData::GetTriangleStripData

<!-- tags: wall/layout, method/diagnostic -->

- Function: 0xf19150 NiTriStripsData::GetTriangleStripData
- Label: CRASHLOGGER_PDB(59818@2026.10.24); SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: PASS; 49/49 exact code bytes
- Attempts: 3 (two drafting comparisons and one final declaration-label comparison)

## What differed
The first handwritten query compiled to 43 bytes against a 49-byte target. It returned the sum of the triangle count and twice the strip count directly as a 32-bit output. The target preserves a 16-bit intermediate before widening that result. The community layout supplied field names and offsets, while the permitted sibling header supplied the method name and output declarations; no sibling middleware body was read.

## Spellings tried that did not help
Assigning the promoted arithmetic expression directly to the 32-bit output produced the shorter mismatching function.

## Spelling that fixed it
Narrow the complete element-count expression to an unsigned 16-bit value before assigning the 32-bit output. Keep the strip-count output and the two array outputs in their observed order. The second local comparison passed under the default recipe; the third confirmed the final declaration labels and source digest. This is a candidate, not acceptance.
