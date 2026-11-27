# 0xfb8a70 NiPSysRotationModifier::IsEqual

<!-- tags: abi/calling-convention, construct/float, wall/register-schedule -->

- Function: 0xfb8a70 NiPSysRotationModifier::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 45/146 matching bytes; alignment distance 2; 45 target and candidate instruction shapes
- Attempts: 3 compares; 81 one-worker permutation candidates

## What differed
The base equality call, scalar field comparisons, virtual boundary and control-flow shape agree. The remaining alignment difference is a swap of the two callee-saved pointer roles, including their saves and restores. This is another instance of cookbook rule 12; matching instruction shapes does not establish a byte match.

## Spellings tried that did not help
Moving the typed peer declaration before the base call and returning the comparison result directly both retained the same measured score. The bounded PC permutation search retained distance 2 after 81 candidates and stopped on patience. Fast floating point removes the unwanted parity checks, as described by cookbook rule 48, but does not resolve the register choice.

## Spelling that fixed it
none. The original handwritten draft and every compare remain private for later investigation.
