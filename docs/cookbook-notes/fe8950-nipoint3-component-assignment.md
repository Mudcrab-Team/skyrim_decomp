# 0xfe8950 BSOcclusionPlane::GetCornersRelativeTo

<!-- tags: construct/float, construct/vector, wall/register-schedule -->

- Function: 0xfe8950 BSOcclusionPlane::GetCornersRelativeTo
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: float-codegen
- Best score: 256/256 bytes, local comparator pass
- Attempts: 5

## What differed

Assigning the subtracted corner coordinates directly element-by-element (`dst[i].x = ...; dst[i].y = ...; dst[i].z = ...;`) interleaved the loads and stores differently from the target, while returning `NiPoint3` by value with the compiler-generated copy assignment caused MSVC 19.16 to pack the first two floats into a 64-bit move and spill the third float through the stack.

## Spellings tried that did not help

- Direct field-by-field subtraction into `destination[i].x/y/z`: right instruction count, wrong float register and load/store interleaving.
- Inline `NiPoint3::operator-` with the trivial implicit copy assignment: added a 16-byte stack frame and emitted packed unpack-and-store sequences.

## Spelling that fixed it

Define an explicit component-wise `NiPoint3& operator=(const NiPoint3& rhs)` alongside the inline `operator-` constructor return, and assign `destination[i] = corners[i] - origin;` inside the 4-element loop. The same explicit component-wise assignment also closed `BSOcclusionPlane::InsidePlanes` (`0xfe8fe0`) and `BSOcclusionBox::CreateClone` (`0xfe5aa0`).
