# 0x152aeb0 ImageSpaceShaderParam::~ImageSpaceShaderParam

<!-- tags: abi/exception, construct/destructor -->

- Function: 0x152aeb0 ImageSpaceShaderParam::~ImageSpaceShaderParam
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: unsolved
- Cause: other
- Best score: 280/280 (aligned_matching_bytes)
- Attempts: 4

## What differed

All 280 code bytes and 69 instructions match the target identically, including the inlined array destructors and exception-handling call-site padding, but `FuncInfo.max_state` differs from the target (`eh-data-mismatch`).

## Spellings tried that did not help

- Standalone `NiTPrimitiveArray` and `NiTObjectArray` classes with virtual destructors reproduced 280/280 code bytes with `max_state == 1`, failing on `FuncInfo.max_state`.
- Deriving both array types from `NiTArray<T>` with `virtual ~NiTArray() {}` and overriding in derived classes prevented inlining of `~NiTObjectArray` (`236/280` bytes).
- Putting `TAlloc::Deallocate(data)` in `NiTArray<T, TAlloc>::~NiTArray()` with defaulted or empty derived destructors reproduced all 280/280 code bytes again, but still emitted `max_state == 1`.

## Spelling that fixed it

none
