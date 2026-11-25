// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock148960: GUESS(low) STANDIN; original owner is unknown
// Function148960: GUESS(low); provisional entry name
// 0x148960 Unlock148960::Function148960
#include "Unlock148960.h"

std::uint32_t Unlock148960::Function148960()
{
    if (TestFlag(baseEffect->flags, 9)) return 0;
    return duration;
}
