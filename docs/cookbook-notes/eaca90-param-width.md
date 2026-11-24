# 0xeaca90 InlMalloc

- Function: 0xeaca90 InlMalloc
- Label: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: all 4 differing instructions of the 20-instruction sibling body closed in a recompile; comparator not run
- Attempts: 1 recompile of the sibling unit as x64 with the project recipe

## What differed
The sibling x64 body of this small allocation helper has the same 20 instructions as the target. Four
differ, all by operand width: the zero test and the conditional move on the size use 32-bit registers
where the target uses 64-bit ones, and the two stack slots that hold the size and the alignment are
written as 4-byte stores where the target writes 8 bytes. The sibling declares the size and the alignment
as 32-bit integers because it was decompiled for a 32-bit build.

## Spellings tried that did not help
- Widening only the helper's own parameter: the allocator call takes the size and alignment by
  reference, so the value must have the same type as the callee's reference parameters; a 32-bit
  parameter forwarded to a `size_t&` parameter does not compile.

## Spelling that fixed it
Make the size and the alignment 64-bit all the way down: the helper's parameter, the forwarding member
and the reference parameters of the allocator's virtual (`size_t`). The three width hunks disappear
together because the reference parameters decide the width of the spilled slots. Where a caller still
holds a 32-bit local, copy it into a `size_t` temporary at the call.

```cpp
static inline void* InlMalloc(size_t size) { if (size == 0) size = 1; return mgr->Allocate(size, 4, 11, false, 0, -1, 0); }
virtual void* Alloc(size_t& size, size_t& alignment, int event, bool accurate, const char* file, int line, const char* fn);
```
