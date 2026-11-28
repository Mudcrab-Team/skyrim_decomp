# 0x253160 Obj253160::RemoveAt

<!-- tags: abi/exception, wall/register-schedule -->

- Function: 0x253160 Obj253160::RemoveAt
- Label: none
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 126/126 code bytes (unwind-coverage-missing)
- Attempts: 1

## What differed

All code bytes matched the target range, including the late save of the second non-volatile register after the early bounds check. The target binary emitted three chained unwind table entries covering the shrink-wrapped save region, while the pinned compiler emitted a single unwind table entry with an extended prologue length. The same single-entry versus multi-entry unwind difference also appeared in 0x2555e0 when all code bytes matched.

## Spellings tried that did not help

- Standard early return before saving the second non-volatile register inside the bounds-checked branch.

## Spelling that fixed it

none
