# 0xffed40 BSInvMarker::CopyMembers

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0xffed40 BSInvMarker::CopyMembers
- Label: CRASHLOGGER_PDB(59818@2026.10.24); CopyMembers GUESS(low)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 63/68 aligned matching bytes; equal function extent, distance 0.5
- Attempts: 6 counted comparisons; 6 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The best copy implementation has one reordered pair of independent member loads. Its registers, float transport, stores, base call and function extent otherwise agree in the inspected alignment. The compiler schedules the two short-member loads differently. This is another instance of the float-copy family already recorded in cookbook rule 45.

## Spellings tried that did not help

- Named scalar locals for all four copied members: 29/68. The float travels through an integer register.
- An inline member setter receiving the values: 32/68, with reversed argument loading and integer float transport.
- SIMD load/store of the float with the three short locals: 47/68, distance 1.5, register differences only.
- Bounded PC permutation search: 257 candidates improved distance from 1.5 to 0.5 by swapping the first two short declarations; normal comparison measured 63/68.
- Split declaration of the second short followed by source-order assignments: 47/68, distance 1.5.

## Spelling that fixed it

none. The best declaration-swap source was restored for the final comparison at the six-comparison cap. Failed drafts, search results and diagnostics remain private for scheduling investigation.
