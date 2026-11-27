# 0x150ba00 BSImagespaceShaderCopyCustomViewport::Function150ba00

<!-- tags: method/diagnostic -->

- Function: 0x150ba00 BSImagespaceShaderCopyCustomViewport::Function150ba00
- Label: GUESS(low)
- Outcome: fixed
- Cause: instruction-order
- Best score: 54/54
- Attempts: 4

## What differed

The target copies 16 bytes from a member to a stack temporary with an unaligned vector load and store, then passes the temporary's address. A by-value struct parameter of four floats gave an aligned store to the temporary.

## Spellings tried that did not help

By-value struct argument (aligned store). Named local copy by assignment (aligned store). A struct of two 64-bit integers (aligned store).

## Spelling that fixed it

Make the callee take a pointer and copy with `std::memcpy(&rect, &viewport, sizeof(rect));` into a local, then pass `&rect`. The compiler emits an unaligned load and store. For a constant source, `alignas(16)` on the static constant gave the aligned load the target has (0x150b7c0, copy placed before the member stores).
