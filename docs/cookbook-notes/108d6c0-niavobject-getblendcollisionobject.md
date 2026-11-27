# 0x108d6c0 NiAVObject::GetBlendCollisionObject

<!-- tags: wall/register-schedule, wall/control-flow -->

- Function: 0x108d6c0 NiAVObject::GetBlendCollisionObject
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 86/88 (aligned_matching_bytes)
- Attempts: 5

## What differed

The candidate reproduced all thirty instructions of the body and the RTTI walk, but emitted an extra duplicate epilogue on the null-object early exit because the compiler shrink-wrapped the callee-saved register save inside the non-null branch instead of saving it unconditionally in the prologue.

## Spellings tried that did not help

- Checking the object pointer and its collision pointer in separate nested `if` statements with an `IsKindOf` loop helper.
- Returning directly from an early-exit null check before calling a separate `CastToBlendCollisionObject` helper.
- Writing the RTTI pointer walk inline inside the member function instead of a helper.
- Changing the parameter check to a combined `if (object && object->collisionObject)` condition.
- Using a `do`/`while` loop for the RTTI base chain walk.

## Spelling that fixed it

none
