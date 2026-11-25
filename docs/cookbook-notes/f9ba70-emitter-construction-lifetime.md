# 0xf9ba70 NiPSysEmitterCtlr::ctor

<!-- tags: construct/constructor, abi/exception, wall/layout, wall/inlining -->

- Function: 0xf9ba70 NiPSysEmitterCtlr::ctor
- Label: EXE_RTTI
- Outcome: unsolved
- Cause: struct-layout
- Best score: 22/85 aligned matching bytes
- Attempts: 2

## What differed
The observed class table identifies NiPSysEmitterCtlr and its NiPSysModifierCtlr parent. The candidate initializes the observed scalar and pointer fields, but construction lifetime handling and the final container initialization remain unresolved. Both comparisons reported a function size mismatch, with 22/85 aligned matching bytes.

## Spellings tried that did not help
A scalar-only member model and a second model with owned-pointer members and an inline empty container constructor both measured 22/85. The permitted Fallout 3 declaration supplied shape leads only; no middleware implementation body was inspected or adapted.

## Spelling that fixed it
None. The source diagnosis reached the five-minute per-function limit and stopped. The unresolved constructor/container boundary needs stronger layout and lifetime evidence before further matching work. This was not a register-only wall, so no permutation search was run.
