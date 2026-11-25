# 0x7a4950 MovementHandlerAgentPlayerControls::Func12_1406FC1F0

<!-- tags: abi/virtual, construct/serialization, wall/callee -->

- Function: 0x7a4950 MovementHandlerAgentPlayerControls::Func12_1406FC1F0
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: calling-convention
- Best score: comparator PASS; previously 70/74 matching bytes, alignment distance 3
- Attempts: 3

## What differed
The initial body kept the scalar stream output local in scope through two later reads. Its last virtual read remained a call followed by a return, while the target used a tail transfer. The first two comparisons had the same alignment distance and no reported behavioral-value differences. Cookbook rule 46 identifies this boundary, including an unresolved related movement function.

## Spellings tried that did not help
Returning a small scalar wrapper through caller storage preserved the initial 70/74 matching bytes and distance 3. Permitted sibling game-code study supplied naming context; no sibling body was adapted.

## Spelling that fixed it
A single measured bundle narrows the scalar output local to a block containing its read and assignment, then explicitly returns the final virtual call after the second read. Comparison three passed with the default recipe. This establishes the combined spelling on this function; it does not isolate either edit as sufficient alone. The stream declarations and opaque destination types remain low-confidence stand-ins. Local PASS remains candidate evidence pending independent acceptance.
