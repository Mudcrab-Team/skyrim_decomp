# 0xf758d0 NiBoolInterpolator::SaveBinary

<!-- tags: abi/virtual, construct/serialization, wall/callee -->

- Function: 0xf758d0 NiBoolInterpolator::SaveBinary
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: calling-convention
- Best score: comparator PASS; initial 98/102 matching bytes, alignment distance 3
- Attempts: 3 (2 to close; 1 final provenance-label digest confirmation)

## What differed
The initial original draft kept an address-taken component-size local alive through the final virtual link-save call. The compiler emitted a normal final call and return where the target used a tail transfer. The first comparison matched 98 of 102 bytes.

## Spellings tried that did not help
The direct write with the size local in the function's outer scope retained the final normal call. No sibling implementation body was read or adapted.

## Spelling that fixed it
Place the size local, output-stream pointer and write expression in a lexical block that ends before SaveLinkID. The second comparison passed with no other body edit. A third comparison confirms the corrected name-origin label. This isolates lexical lifetime as sufficient for this function and complements the combined edit recorded for 0x7a4950. Local PASS remains candidate evidence pending independent acceptance.
