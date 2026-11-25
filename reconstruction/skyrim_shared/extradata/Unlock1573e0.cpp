// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock1573e0: GUESS(low) STANDIN; original owner is unknown
// Function1573e0: GUESS(low); provisional entry name
// 0x1573e0 Unlock1573e0::Function1573e0
#include "Unlock1573e0.h"

bool Unlock1573e0::Function1573e0(std::uint32_t type)
{
    if (presence) {
        std::uint32_t index = type >> 3;
        if (index < 23) return (presence[index] & (1 << (type & 7))) != 0;
    }
    return false;
}
