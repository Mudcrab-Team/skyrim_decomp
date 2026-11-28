// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e34d0 Unit1e34d0::GetFactoryName1e34d0
// Adapted bodies: none
#include "Unit1e34d0.h"

#include <cstring>

// Looks up the factory for a type byte and returns its name, or a default fallback string.
const char* Unit1e34d0::GetFactoryName1e34d0(std::uint8_t a_type)
{
    if (!g_tableInitialized1e34d0) {
        std::memset(g_factoryTable1e34d0, 0, sizeof(g_factoryTable1e34d0));
        g_tableInitialized1e34d0 = true;
    }
    if (a_type < kTableCount && g_factoryTable1e34d0[a_type]) {
        return g_factoryTable1e34d0[a_type]->GetName();
    }
    return g_defaultName1e34d0;
}
