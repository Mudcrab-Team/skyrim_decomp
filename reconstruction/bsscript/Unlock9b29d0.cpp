// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock9b29d0: GUESS(low) STANDIN; original owner is unknown
// Function9b29d0: GUESS(low); provisional entry name
// 0x9b29d0 Unlock9b29d0::Function9b29d0
#include "Unlock9b29d0.h"

void Unlock9b29d0::Function9b29d0(std::int32_t index)
{
    if (!initialized9b) { std::memset(entries9b, 0, sizeof(entries9b)); initialized9b = true; }
    if (index < 25) entries9b[index] = nullptr;
}
