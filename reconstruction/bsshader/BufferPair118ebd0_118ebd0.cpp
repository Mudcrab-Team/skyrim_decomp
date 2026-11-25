// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BufferPair118ebd0: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function118ebd0: GUESS(low); provisional member name
// 0x118ebd0 BufferPair118ebd0::Function118ebd0
// CI hash: 0x118ebd0 ?Function118ebd0@BufferPair118ebd0@@QEAAXXZ
#include "BufferPair118ebd0_118ebd0.h"

// Guess: Release a paired buffer resource through its allocator or resource interface; layout does not support a shader-property owner.
void BufferPair118ebd0::Function118ebd0()
{
    if (active) {
        if (allocator) {
            allocator->Release(first);
            allocator->Release(second);
        } else {
            if (first) { first->Release(); }
            if (second) { second->Release(); }
        }
    }
    first = nullptr;
    second = nullptr;
}
