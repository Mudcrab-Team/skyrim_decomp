# 0xf9f3e0 NiPSysCylinderEmitter::LoadBinary

<!-- tags: construct/serialization, wall/inlining, wall/register-schedule -->

- Function: 0xf9f3e0 NiPSysCylinderEmitter::LoadBinary
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: 120/136 aligned matching bytes before the fix; local comparator PASS 136/136 after
- Attempts: 3 counted comparisons; one bounded one-worker permutation search

## What differed

The base call and two field transfers had the correct references and extent. Two independent stack stores before the second transfer were emitted in the opposite order. The alignment distance was 1.0. This was scheduling residue rather than a differing field offset or constant value.

## Spellings tried that did not help

One reusable component-size local and separate lexical scopes both retained 120/136 aligned matching bytes. The bounded permutation search exhausted 73 candidates at distance 1.0 without improvement.

## Spelling that fixed it

Use an ordinary typed transfer helper containing the component-size local and the stream callback plus position update. Call it once per field. Its inline boundary produced the observed scheduling, and the unchanged native comparator passed on comparison 3. The corresponding SaveBinary helper passed on its first comparison at 0xf9f490. These are local candidate results, pending independent acceptance. The bodies are original from target observations and labelled declarations; no sibling middleware body was read or adapted.
