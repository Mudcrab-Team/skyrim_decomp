# 0x1eb900 Reserve array capacity for additional elements

<!-- tags: construct/allocation, construct/destructor -->

- Function: 0x1eb900 ReserveAdditional
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 74/74 primary bytes and a 12-byte exception cleanup
- Attempts: 5 development comparisons, including the final symbol binding

## What differed

The fast path returns when the existing allocation can accommodate the current size plus the requested count. The growth path puts an allocator functor on the stack and calls the capacity helper at 0xce0c10 with the old capacity, the required count and the element width. Other array wrappers call the same helper unconditionally. The branch and its arguments distinguish this operation.

## Spellings tried that did not help

With a compiler-generated functor destructor, the development function compiled to 64 bytes and lacked the target cleanup. Declaring the destructors in the functor hierarchy with bodies produced the 74-byte extent. Computing the required count before reading capacity still left two operations in a different order.

## Spelling that fixed it

Read the used count, read capacity, then add the requested count to the saved size. Construct the functor only if growth is required. Bind its vtable using the image RTTI and its destructor using the exception action's tail call. The primary hash agreed before the destructor was bound. Binding it allowed the comparator to verify the cleanup too.

On the pinned Steam 1.7.104 executable, the allocator RTTI identifies BSTArrayHeapAllocator and BSScrapArrayAllocator. The size and capacity offsets agree with their different storage layouts. The element width comes from the capacity call. Element identities and the original method name remain unknown. Source exposure was mixed, using local binary analysis and the project's community-derived allocator declarations (CommonLibSSE-NG at b93280e, MIT). The survey used repository revision ef8581d858.

The frozen template passed the full local comparator and published hash check on the development member and all 31 held-out functions. The 15 heap and 17 scrap specializations span nine element widths and 2,368 primary bytes. Each also passed a 12-byte cleanup comparison. The existing array generator excludes exception-handler functions. No matched or claimed extent overlapped this cohort at the survey revision.
