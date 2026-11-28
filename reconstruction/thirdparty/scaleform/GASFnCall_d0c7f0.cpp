// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xd0c7f0 GASFnCall::Arg
#include "GASFnCall_d0c7f0.h"

// Return a pointer to the requested call argument from the paged environment stack, or null if out of range.
GASValue* GASFnCall::Arg(std::uint32_t a_index)
{
    GASEnvironment* stackEnv = env;
    std::uint32_t index = firstArgBottomIndex - a_index;
    std::uint32_t topIndex = ((stackEnv->numPages - 1) << 5) +
        static_cast<std::uint32_t>(stackEnv->current - stackEnv->pageStart);
    GASValue* result = nullptr;
    if (index <= topIndex) {
        result = stackEnv->pages[index >> 5] + (index & 0x1F);
    }
    return result;
}
