// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock148900: GUESS(low) STANDIN; original owner is unknown
// Function148900: GUESS(low); provisional entry name
// 0x148900 Unlock148900::Function148900
#include "Unlock148900.h"

std::uint32_t Unlock148900::Function148900()
{
    if (TestFlag(baseEffect->flags, 11)) return 0;
    return area;
}
