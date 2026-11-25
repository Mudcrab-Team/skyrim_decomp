# 0xfa0290 NiPSysEmitter::IsEqual

<!-- tags: construct/float, wall/register-schedule -->

- Function: 0xfa0290 NiPSysEmitter::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: operand-order
- Best score: 221/221 aligned matching bytes; local PASS
- Attempts: 2 counted comparisons; one exempt compile failure; 81 permutation candidates

## What differed
The fourteen scalar comparisons and overall extent agreed, but the equality tests used the opposite object as the first floating operand. The comparison classified the residue as register renaming plus prologue/unwind, with distance 2.0 and 71/221 aligned matching bytes. All references were resolved. This extends the operand-order observation in near-tier lesson 31 to an equality chain.

## Spellings tried that did not help
A bounded one-worker permutation search tested 81 candidates and retained distance 2.0. The original spelling compared each member against the corresponding member of the other object.

## Spelling that fixed it
Reverse both operands of every scalar inequality, preserving the field order and early returns. Comparing the other object's member against this object's member made the local comparator pass. The fast floating recipe was held fixed across both comparisons. Naming and layout hints came from CrashLogger and existing community declarations; the implementation was written from local target observations, with no sibling body adapted. This local result is a candidate and does not establish acceptance.
