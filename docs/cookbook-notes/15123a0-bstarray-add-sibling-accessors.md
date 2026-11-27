# 0x15123a0 BSTArray<NiPointer<BSLight>>::Add

<!-- tags: construct/allocation, method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0x15123a0 BSTArray<NiPointer<BSLight>>::Add (also 0x1512410, 0x1512470, 0x15124e0, 0x150d120, 0x150cff0)
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: register-allocation
- Best score: size matched from the first draft; index and base registers differed, then a byte match
- Attempts: 8

## What differed
The array append helpers (allocator functor on the stack, grow call, element store with a reference-count increment) matched
the target's size at once but swapped the index and base registers around the element store. Callers that copy a counted
pointer (`QueueLightAdd`, the by-node remover) also reloaded the pointer from its stack slot after the call and tested it
again, and their copy stored the pointer twice in the target.

## Spellings tried that did not help
- Reading the buffer and the allocation size from the members directly instead of through accessors.
- A counted pointer whose copy constructor stores once.
- Passing the counted pointer by value: the compiler passed the raw pointer and dropped the release.

## Spelling that fixed it
Follow the sibling container exactly: `Add` calls `AddUninitialized(BSTArrayAllocatorFunctor<A>(this), QAllocSize(),
sizeof(T))`, and every access goes through `A::QBuffer()` and `A::QAllocSize()` accessors (inline members of the heap
allocator). The counted pointer is the sibling `NiPointer`: its copy constructor initialises the member from the argument and
then assigns `Acquire(arg)` (two stores), and `QueueLightAdd` is defined in the same unit as a noinline member so the
caller's analysis keeps the pointer in a register. Explicit instantiations with a `CI hash:` line each carry the decorated
name. One instance (0x15122e0) still differs by one register pair.
