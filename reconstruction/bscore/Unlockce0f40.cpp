// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockce0f40: GUESS(low) STANDIN; original owner is unknown
// Functionce0f40: GUESS(low); provisional entry name
// 0xce0f40 Unlockce0f40::Functionce0f40
#include "Unlockce0f40.h"

void Unlockce0f40::Functionce0f40(void* first, void* second, void* temp, std::uint32_t bytes)
{
    memmove_s(temp, bytes, first, bytes);
    memmove_s(first, bytes, second, bytes);
    memmove_s(second, bytes, temp, bytes);
}
