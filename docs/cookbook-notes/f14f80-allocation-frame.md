# 0xf14f80 ParticleCreateLeaff14f80::CreateOldRotatingParticlesObject

<!-- tags: method/sibling, sibling/fo4, abi/exception -->

- Function: 0xf14f80 ParticleCreateLeaff14f80::CreateOldRotatingParticlesObject
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 60/92 aligned bytes
- Attempts: 1

## What differed
The target retains exception-state bookkeeping and a temporary around allocation and construction. The straightforward placement-new draft emits a different frame.

## Spellings tried that did not help
- Explicit allocator readiness, allocation and conditional placement construction matched 60/92 aligned bytes.

## Spelling that fixed it
None.
