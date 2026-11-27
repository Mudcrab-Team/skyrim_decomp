# 0x213170 BSPortal::Create

<!-- tags: construct/allocation, construct/constructor, wall/register-schedule -->

- Function: 0x213170 BSPortal::Create
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: struct-layout
- Best score: 268/290 aligned bytes (69/69 instructions, 4 stack-slot offsets differ)
- Attempts: 6

## What differed

All 69 instructions, exception cleanup, and member initializations match in order and length, but two 8-byte temporaries swap stack slots: the compiler places the `operator new` return temporary in a home slot and the `NiPoint2` temporary in the adjacent home slot, whereas the target stores the allocation pointer in a lower local slot and builds `NiPoint2` in the upper home slot.

## Spellings tried that did not help

- Constructing `NiPoint2(width, height)` inside `BSPortal(float width, float height)`.
- Constructing `NiPoint2(primitive->bounds.x, primitive->bounds.z)` at the call site and passing `const NiPoint2&` to `BSPortal`.

## Spelling that fixed it

none
