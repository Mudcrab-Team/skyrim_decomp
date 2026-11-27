# 0x1581e90 BSShadowDirectionalLight::`scalar deleting destructor'

<!-- tags: construct/destructor, abi/exception, wall/inlining -->

- Function: 0x1581e90 BSShadowDirectionalLight::`scalar deleting destructor'
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: inlining
- Best score: 370/370 aligned matching bytes
- Attempts: 2 comparisons

## What differed
The earlier round called the array `Clear` and the base destructors out of line, and had fewer exception states than the
target.

## Spellings tried that did not help
The arrays as members with their implicit destructors while `Clear` stayed out of line: the teardown stayed a call.

## Spelling that fixed it
- Declare the culling-process base destructor as virtual in its real slot (slot 0x15 in the vtable), so the derived
  destructor chains through the right base teardown.
- Drop `noinline` from the shared array `Clear`, so the array teardown inlines to the conditional form (free when the
  buffer exists, otherwise the second helper) and the exception states line up.
