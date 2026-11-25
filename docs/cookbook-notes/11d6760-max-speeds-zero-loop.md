# 0x11d6760 ActorState::ReadMaxSpeedComponent

<!-- tags: abi/virtual, construct/constructor, construct/loop, construct/vector, method/diagnostic, wall/control-flow -->

- Function: 0x11d6760 ActorState::ReadMaxSpeedComponent
- Label: GUESS(low)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 38/69 aligned matching bytes; distance 13; candidate 71 bytes, target 69; comparator FAIL
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The local output buffer must be cleared before a virtual call. The target keeps a counted loop over five pairs of components and clears the final component separately. The best matching-byte drafts instead use vector stores and a wider scalar store. The virtual slot and successful return component agree, but that does not establish a byte match. The component name and pair grouping remain guesses; the body is original and was informed by authorized local binary analysis, community declarations and symbol-name evidence.

## Spellings tried that did not help
- A range loop over eleven floats: 21/69 aligned matching bytes; candidate 80 bytes.
- Five aggregate pair assignments plus the final component: 25/69; candidate 69 bytes; expanded scalar stores, distance 12.5.
- Pair default constructors: unchanged at 25/69, distance 12.5.
- A 64-bit countdown over pairs: 38/69; vector stores, distance 13.
- A 32-bit countdown with explicit component stores: unchanged at 38/69.
- A 64-bit do-while countdown with explicit component stores: unchanged at 38/69; candidate 71 bytes, comparator FAIL.

## Spelling that fixed it
None. This repeats cookbook rule 57 with six measured comparisons. The residue is a loop/vectorization difference, not solely register allocation or scheduling, so no permutation search was run for this target. The final compared source and all earlier spellings are retained privately; it is withheld from the passing-source set. The six-comparison cap ended drafting.
