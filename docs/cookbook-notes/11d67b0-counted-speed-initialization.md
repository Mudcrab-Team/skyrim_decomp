# 0x11d67b0 ActorState::GetForwardRunSpeed

<!-- tags: construct/constructor, construct/loop, wall/register-schedule -->

- Function: 0x11d67b0 ActorState::GetForwardRunSpeed
- Label: GUESS(low)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 54/69 aligned matching bytes; final restored source reproduced 54/69
- Attempts: 5 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The best source clears each pair of directional speed values in a pointer-bounded loop. The target retains a descending count for that initialization. The virtual query and selected forward-running result agree in the inspected alignment, but the initialization sequence does not. This extends the unsuccessful initialization experiments recorded in cookbook rule 57; no byte match was obtained.

## Spellings tried that did not help

- The preserved range loop over pairs: 54/69 aligned matching bytes.
- A size-sized descending counter with a pair pointer: 38/69; the compiler replaced the loop with bulk stores.
- Aggregate value initialization: 25/69; the clear sequence and register selection differed.
- A directional pair with a default constructor and scalar zero initializers: 38/69; bulk stores remained.
- Restoring the range loop with final provenance: 54/69, confirming the best source after three consecutive non-improving comparisons.

- Structural pass: an index loop with the two stores per pair compiles to vector stores (distance 13), the pointer range-for stays at 13 with a pointer-compare loop; the target is a five-iteration loop with one eight-byte zero store per pair and a decrementing counter, so the original zeroes whole pairs (a pair type with an assignment or constructor), not floats.

## Spelling that fixed it

none. The best source and its companion header remain private for further loop-shape investigation. The residue changes the initialization instruction sequence, so it was not classified as register-only or scheduling-only and no permutation search was run.
