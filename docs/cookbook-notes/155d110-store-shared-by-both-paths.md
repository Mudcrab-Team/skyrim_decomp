# 0x155d110 BSShadowDirectionalLight::SetupFocusShadowAccumulators

<!-- tags: wall/control-flow, construct/allocation, abi/exception -->

- Function: 0x155d110 BSShadowDirectionalLight::SetupFocusShadowAccumulators
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: branch-layout
- Best score: 340/340 bytes with unwind and exception data
- Attempts: 3

## What differed
For each focus descriptor the function sets a flag, creates a shader accumulator when none exists (class allocator, once-init
guard, constructor, smart-pointer assignment) and fills it, then asks it to accumulate a scene root. The first draft matched in
size, with two jumps different: one field of the new accumulator was stored inside the "create" block, while the target stores it
for both the new and the existing accumulator.

## Spellings tried that did not help
None needed beyond the move below.

## Spelling that fixed it
When a branch of the target jumps into the middle of another block, the instructions after the landing point run for both
paths: read the jump targets. Here the existing-accumulator path lands on the store of the shared field, so that store sits after
the closing brace of the `if (!accumulator)` block, written through the descriptor's smart pointer (which is read again from the
member each time). The class allocator for the accumulator is a `throw()` `operator new` that forwards to the engine allocator,
which gives the null test before the constructor and the stack slot for the new-expression cleanup.
