# 0xf61440 NiFloatInterpolator::SaveBinary

<!-- tags: abi/calling-convention, construct/serialization, method/diagnostic, wall/register-schedule -->

- Function: 0xf61440 NiFloatInterpolator::SaveBinary
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 98/102 aligned matching bytes; distance 3.0
- Attempts: 1

## What differed

The original draft saves its base, writes the float through the stream callback, updates the stream position, and saves the data link. The comparator reports frame and argument-setup residue. All references bind and the alignment reports no behavior mismatches. The result remains a local failure.

## Spellings tried that did not help

The bounded PC permutation search used one worker and scored 81 candidates. Its best distance remained 3.0; no generated spelling was applied. The source uses community stream declarations and target observations; no excluded sibling body was read.

## Spelling that fixed it

None. Keep the handwritten draft for frame and argument-setup investigation. The alignment score alone does not identify a register-only cause.
