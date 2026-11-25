# 0x449390 BGSAIWorldLocationInteriorCell::GetWorldLocation

<!-- tags: wall/register-schedule, construct/float -->

- Function: 0x449390 BGSAIWorldLocationInteriorCell::GetWorldLocation
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 39/42 matching bytes; alignment distance 0.5
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
Two independent initial member loads stayed in the opposite order. The remaining scalar copy, pointer output and success predicate aligned. This reproduces the operand-order wall described by cookbook rule 42.

## Spellings tried that did not help
An integer first coordinate with scalar locals, a float first coordinate with the same locals, and storing the output pointer before the final coordinate each measured distance 0.5. A bounded one-worker permutation run tested 241 candidates and retained distance 0.5.

## Spelling that fixed it
none
