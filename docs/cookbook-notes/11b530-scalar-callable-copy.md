# 0x11b530 std::_Func_impl_no_alloc::_Move

<!-- tags: construct/vector, wall/register-schedule -->

- Function: 0x11b530 std::_Func_impl_no_alloc::_Move
- Label: GUESS(low) STANDIN
- Outcome: fixed
- Cause: instruction-order
- Best score: full native comparator pass for 39 two-word copy and move slots
- Attempts: 3

## What differed

The callable copies its two stored words separately. A vector copy of the
same storage width has a different instruction shape. Each candidate must use
the vftable independently bound to its own slot.

## Spellings tried that did not help

The existing contiguous storage template models the vector-copy family.
The two-word scalar family needs separate field copies.

## Spelling that fixed it

Model the callable state as two fields and give it memberwise copy and move
constructors. Explicitly instantiate the standard template over that state.
Both a pointer and integer pair and a pair of pointer fields passed the
native comparator. The published stand-in uses a pointer and an integer,
with the original field types unknown.
