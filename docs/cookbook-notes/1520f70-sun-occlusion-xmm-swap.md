# 0x1520f70 BSShaderAccumulator::UpdateSunOcclusionTestResults

<!-- tags: construct/float, construct/loop, wall/register-schedule -->

- Function: 0x1520f70 BSShaderAccumulator::UpdateSunOcclusionTestResults
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 322/350 aligned bytes (94/94 instructions, 7 differing rows)
- Attempts: 5

## What differed

All 94 instructions and control-flow blocks agree, including the inlined single-slot update and the reset loop, except two callee-saved floating-point registers are swapped: the zero constant and the running maximum occlusion accumulator trade registers, shifting two branch encodings by one byte each.

## Spellings tried that did not help

- Reversing the comparison operand order (`maxOccluded < percentOccluded` vs `percentOccluded > maxOccluded`).
- Reordering the accumulator local declarations before the loop.

## Spelling that fixed it

none
