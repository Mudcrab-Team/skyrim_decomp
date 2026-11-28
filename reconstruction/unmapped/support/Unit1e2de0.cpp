// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e2de0 Unit1e2de0::RegisterFactory1e2de0
// Adapted bodies: none
#include "Unit1e2de0.h"

#include <cstring>

// Zero-initializes the factory table on first use and registers a factory at the given type slot.
void Unit1e2de0::RegisterFactory1e2de0(std::uint8_t a_type, void* a_factory)
{
    if (!g_tableInitialized1e2de0) {
        std::memset(g_factoryTable1e2de0, 0, sizeof(g_factoryTable1e2de0));
        g_tableInitialized1e2de0 = true;
    }
    if (a_type < kTableCount) {
        g_factoryTable1e2de0[a_type] = a_factory;
    }
}
