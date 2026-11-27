# 0xfa19c0 NiPSysMeshUpdateModifier::IsEqual

<!-- tags: construct/loop, wall/control-flow, abi/virtual -->

- Function: 0xfa19c0 NiPSysMeshUpdateModifier::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: loop-shape
- Best score: 138/174 aligned matching bytes
- Attempts: 6 counted comparisons, plus one binding-only attempt

## What differed
The reconstructed mesh-array equality loop retained different bound-check and null-branch organization. The best candidate was 168 bytes for a 174-byte target. Reference bindings were resolved, and this was not solely a register-allocation difference.

## Spellings tried that did not help
A nested null check improved when rewritten as a symmetric pair check followed by a one-null check. A full-width loop counter outperformed a narrow counter, but neither accessor index width closed the remaining loop differences. Correcting an omitted virtual declaration removed a call-slot discrepancy without closing the body.

## Spelling that fixed it
none
