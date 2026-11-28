# 0x240480 Obj240480::scalar deleting destructor

<!-- tags: abi/exception, construct/destructor -->

- Function: 0x240480 Obj240480::scalar deleting destructor
- Label: none
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 133/134 bytes (function-size-mismatch)
- Attempts: 3

## What differed

The iterative linked-list deletion loop and recursive scalar deleting destructor body matched closely, and the same shape appears identically at 0x24fbc0. The target scalar deleting destructor reserves an exception-handling state slot in its prologue and emits no-op padding after each recursive delete call, whereas the compiler treats the non-virtual destructor and its inline helper as non-throwing and omits the exception-handling frame.

## Spellings tried that did not help

- Out-of-line destructor body (scalar deleting destructor did not inline the loop).
- Inline destructor body with a helper calling delete (inlined the loop at 133 bytes without an exception-handling frame).
- Inline destructor calling an inline RemoveAll helper method (same 133-byte output without an exception-handling frame).

## Spelling that fixed it

none
