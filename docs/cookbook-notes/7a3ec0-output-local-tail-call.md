# 0x7a3ec0 MovementHandlerAgentPlayerControls::Func7_1406FB980

<!-- tags: wall/callee, abi/virtual, construct/serialization -->

- Function: 0x7a3ec0 MovementHandlerAgentPlayerControls::Func7_1406FB980
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: calling-convention
- Best score: 43/47 matching bytes; alignment distance 3.0
- Attempts: 3

## What differed
The target transfers to a secondary interface after a virtual read into caller storage. The explicit-output local models the observed accesses, but the compiler retains a final call and return where the target uses a tail transfer. This reproduces cookbook rule 46's existing unresolved cause. Names and signatures beyond the labelled community name remain low-confidence stand-ins.

## Spellings tried that did not help
A scalar wrapper returned through hidden caller storage regressed to 19/47 matching bytes and distance 11.5. Returning the final void call directly restored the original 43/47 and distance 3.0, without closing the tail-transfer difference. The retrieved rule helped identify the known boundary and avoid an unrelated register search. Permitted sibling game-code study supplied context, but no sibling body was adapted.

## Spelling that fixed it
None. The retained source uses an explicit scalar output and the secondary virtual interface. It remains a near miss, with a known structural call boundary rather than solely register allocation.
