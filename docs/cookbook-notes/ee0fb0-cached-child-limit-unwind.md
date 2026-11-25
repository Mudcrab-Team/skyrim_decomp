# 0xee0fb0 NiAVObject::SavePreviousWorldTransformRecursive

<!-- tags: construct/loop, wall/control-flow, abi/exception -->

- Function: 0xee0fb0 NiAVObject::SavePreviousWorldTransformRecursive
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 189/189 code bytes; comparator PASS, unwind covered
- Attempts: 3 counted comparisons on this lead (plus earlier history)

## What differed
The recursive walk reads the child array count once in the target and tests it for zero before saving any callee-saved register, so the spills sit inside the non-empty path. The draft re-read the 16-bit count in the loop condition and spilled earlier, giving distance 11.75; a cached count alone brought it to 2.5 with the spill order still wrong.

## Spellings tried that did not help
- A cached signed count in a for loop (distance 2.5), also with an unsigned 32-bit count.

## Spelling that fixed it
Cache the count in a signed pointer-width local, guard with `if (count > 0)`, and run a `do { ... ++i; } while (i < count)` loop. The explicit guard puts the empty test ahead of the spills, as in the target.
