# 0x637eb0 BGSLoadGameBuffer::ReadBlock16

<!-- tags: construct/vector, construct/serialization, wall/layout -->

- Function: 0x637eb0 BGSLoadGameBuffer::ReadBlock16
- Label: GUESS(low)
- Outcome: fixed
- Cause: struct-layout
- Best score: 45/45 bytes, comparator PASS; previous best 40/45 bytes at distance 2.0
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
An opaque sixteen-byte read forwards a local block to an out-of-line helper. A local SIMD type gave the local stronger alignment than the target's block and selected an aligned store. The remaining difference was store alignment, after matching the load and cursor update. The method and helper names remain guesses; the byte comparison does not establish their original names.

## Spellings tried that did not help
A sixteen-byte memcpy and a plain two-word struct assignment both folded the input address and selected a different scratch register, measuring 27/45 matching bytes at distance 3.5. Loading directly into a SIMD local reached 40/45 at distance 2.0 but retained the aligned store. A bounded permuter run tested 224 candidates without improving that distance.

## Spelling that fixed it
Keep the local as four ordinary floats. Read with an unaligned SIMD load, advance the buffer position, and use an explicit unaligned SIMD store into the ordinary block before calling the helper. Attempt four passed; attempt five compares the same body with the completed intrinsic justification comment.
