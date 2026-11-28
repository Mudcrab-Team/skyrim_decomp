// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e2ea0 Unit1e2ea0::ForEachFactory1e2ea0
// Adapted bodies: none
#include "Unit1e2ea0.h"

// Invokes the visitor for each non-null registered factory until it stops returning continue (1).
void Unit1e2ea0::ForEachFactory1e2ea0(FactoryVisitor1e2ea0* a_visitor)
{
    if (!g_tableInitialized1e2ea0) {
        return;
    }

    std::uint32_t status = 1;
    for (std::uint32_t i = 0; i < kTableCount && status == 1; ++i) {
        if (g_factoryTable1e2ea0[i]) {
            status = a_visitor->Visit(g_factoryTable1e2ea0[i]);
        }
    }
}
