# 0xf19190 NiTriStripsData::GetBlockAllocationSize

<!-- tags: construct/allocation, wall/layout -->

- Function: 0xf19190 NiTriStripsData::GetBlockAllocationSize
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: PASS; 40/40 code bytes covered, 36 exact and 4 reference-bound
- Attempts: 2

## What differed
The strip-list element count is narrowed to an unsigned 16-bit value before adding the strip-length element count. Preserving this intermediate width expresses the allocation query directly. The two count fields use the labelled CrashLogger layout, corroborated by local target observations. This is a first-draft local pass, not acceptance.

## Spellings tried that did not help
None. The handwritten body passed its first comparison; the second comparison verifies the final declaration labels and source digest. No sibling middleware bodies were read.

## Spelling that fixed it
Compute an unsigned 16-bit strip-list length from the triangle count plus twice the strip count. Add the strip count after promotion, multiply by the unsigned-short element size, and add the out-of-line base allocation query. The implemented body uses the known two-byte element size. The base reference is bound from the prepared target pack.
