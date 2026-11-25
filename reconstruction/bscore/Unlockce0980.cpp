// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockce0980: GUESS(low) STANDIN; original owner is unknown
// Functionce0980: GUESS(low); provisional entry name
// 0xce0980 Unlockce0980::Functionce0980
#include "Unlockce0980.h"

void Unlockce0980::Functionce0980(void*, void* data, std::uint32_t first, std::uint32_t last, std::uint32_t count, std::uint32_t stride)
{
    auto* base = static_cast<char*>(data);
    memmove_s(base + static_cast<std::uint32_t>(first * stride),
              static_cast<std::size_t>(-1),
              base + static_cast<std::uint32_t>(last * stride),
              static_cast<std::size_t>(static_cast<std::uint32_t>(count * stride)));
}
