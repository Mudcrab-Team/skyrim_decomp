# 0x326df0 BGSMusicTrack::LoadConditions

<!-- tags: construct/serialization, construct/allocation, sibling/fo4 -->

- Function: 0x326df0 BGSMusicTrack::LoadConditions
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: other
- Best score: 160/160
- Attempts: 3

## What differed

The code bytes matched on the first compile, but the comparator reported `eh-data-mismatch` with
"FuncInfo.n_ip_map differs". The function allocates through the memory manager, builds a small
object with an out-of-line constructor, and its cleanup calls a sized delete. The candidate's table of
instruction-to-state entries was shorter than the target's.

## Spellings tried that did not help

none

## Spelling that fixed it

The two memory-manager callees (the lazy init and the allocate) were declared inside `extern "C"`.
With exception handling on, a C-linkage function is assumed not to throw, so the compiler dropped the
state entries around those calls. Declaring them as ordinary C++ functions (same signature, no
`extern "C"`) kept the entries and the table matched. The data symbols can stay `extern "C"`.

```cpp
void MemMgrEnsure_cde810(void* self, std::uint32_t* state);
void* MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
```

This is the cause rule 26 guessed at for `n_ip_map` counts lower than the target's: a callee the
compiler believes cannot throw. Here the belief came from the linkage, not from a visible body.
