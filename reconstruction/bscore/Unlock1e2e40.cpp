// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock1e2e40: GUESS(low) STANDIN; original owner is unknown
// Function1e2e40: GUESS(low); provisional entry name
// 0x1e2e40 Unlock1e2e40::Function1e2e40
#include "Unlock1e2e40.h"

void Unlock1e2e40::Function1e2e40(std::uint8_t index)
{
    if (!initialized) {
        std::memset(entries, 0, sizeof(entries));
        initialized = true;
    }
    if (index < 138)
        entries[index] = nullptr;
}
