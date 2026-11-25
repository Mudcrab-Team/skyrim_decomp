# 0x80a290 CombatAimController::CalculatePriority

<!-- tags: construct/bitfield, wall/control-flow, wall/inlining, wall/register-schedule -->

- Function: 0x80a290 CombatAimController::CalculatePriority
- Label: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map) SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: other
- Best score: 43/76 aligned bytes; distance 8.5; not a byte match
- Attempts: 6 counted comparisons; 7 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The best reconstruction has 26 instructions against 27 in the target and still fails the unchanged comparator with a code-byte mismatch. The unresolved residue therefore includes a shape difference, rather than being established as a pure register swap. Names and the sibling body supplied leads; only the pinned Skyrim comparison was used to assess identity.

## Spellings tried that did not help
An unsigned bit accessor and early return measured 21/76 aligned bytes. Returning a zero-initialized result through a positive-priority branch improved that to 27/76. A boolean bit accessor improved it to 43/76. A separate named combined-flag bonus reduced it to 12/76. The bounded PC permuter tested 241 candidates and left distance 8.5 unchanged. Lesson retrieval supplied register and shared-tail cautions, but no closing spelling.

## Spelling that fixed it
none
