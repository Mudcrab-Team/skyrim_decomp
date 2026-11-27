# 0x157ed80 BSShadowDirectionalLight::DirShadowLightCulling

<!-- tags: abi/exception, construct/allocation, wall/inlining -->

- Function: 0x157ed80 BSShadowDirectionalLight::DirShadowLightCulling
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: inlining
- Best score: 663/679
- Attempts: 10

## What differed

The function builds a scrap-heap array of culling descriptors (one per cascade), hands each to the job list when there is one, then dispatches a final descriptor. Everything matched except the allocator functor temporary: after the reserve call the target keeps the final reset of the functor's vtable pointer (eleven bytes) where the draft drops it as a dead store, and it loads the culling process pointer before computing the cull mode (the draft computes the mode first). The loop head padding then moves by five bytes.

## Spellings tried that did not help

- The functor as a temporary inside an `&&` condition: bool materialised and a state variable added, larger.
- The functor as a temporary in its own statement, and as a named local in a block: both drop the reset.
- Removing the user-declared destructor of the derived functor, and defining it as an ordinary function of the unit instead of an inline member.
- One permuter run (about 480 candidates): no change.

## Spelling that fixed it

none. Pieces that did help and are worth reusing: declare the array destructor without a body so the engine's own instance is called, read the cascade count into a local before the array is declared, a separate statement for the reserve result, and an explicit zero of the count after the array is constructed (the target stores it after the base constructor call, and only a statement outside the constructor reproduces the unwind no-op there).
