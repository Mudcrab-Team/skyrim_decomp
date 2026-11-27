# 0x1510db0 ShadowSceneNode::TestCachedAABBVisibility

<!-- tags: wall/register-schedule, construct/loop, wall/callee -->

- Function: 0x1510db0 ShadowSceneNode::TestCachedAABBVisibility (also 0x1510c90)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: calling-convention
- Best score: 250/250 and 277/277 bytes with unwind and exception data
- Attempts: 12

## What differed
A cached bound is tested against every room of a portal graph, a list walked with the cookbook's rule 36 shape (a reference to
the element, advance, then use it). That spelling closed a dead address computation, and the draft was then one byte short with the
room pointer in the first free scratch register where the target keeps it in the fourth argument register.

## Spellings tried that did not help
- Nested tests, a copy of the element, a swapped compare, a pointer-to-slot form: all 249 of 250 bytes.
- 480 permuter candidates: best distance unchanged.

## Spelling that fixed it
Rule 5: a live argument register at a call means the callee takes that argument. The room pointer is still in the fourth
argument register when the overlap test is called, because the test takes the room as its fourth parameter
(`bound->Overlaps(box, context, room)`), so the register is no choice of the allocator. With the parameter declared, both
functions matched.
