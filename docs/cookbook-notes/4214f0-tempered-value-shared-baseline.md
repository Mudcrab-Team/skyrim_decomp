# 0x4214f0 TESBoundObject::GetTemperedValue

<!-- tags: construct/float, wall/constant, wall/layout -->

- Function: 0x4214f0 TESBoundObject::GetTemperedValue
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: local comparator PASS, 76/76 bytes
- Attempts: 5

## What differed

The initial draft folded the default maximum into a direct return and produced a smaller function. A shared externally declared baseline preserved the observed common arithmetic path. The final remaining difference was the width of the global availability test.

## Spellings tried that did not help

A literal baseline and either eager initialization or an explicit fallback produced the same 63-byte candidate. An external baseline improved the structure but the direct expression still avoided the observed return-value copies. A 32-bit availability declaration left the function one byte short.

## Spelling that fixed it

Use the shared baseline, assign the return value in both branches, and perform the arithmetic through that local. Declare the availability object as a pointer, matching the observed pointer-width test. The name remains a stand-in. The fifth comparison passed under the task's unchanged recipe. This is local evidence only; independent verification and review remain required.
