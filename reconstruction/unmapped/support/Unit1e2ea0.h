// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// FactoryVisitor1e2ea0, Unit1e2ea0, g_tableInitialized1e2ea0, g_factoryTable1e2ea0, ForEachFactory1e2ea0, Visit, kTableCount: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

constexpr std::size_t kTableCount = 138;

extern bool g_tableInitialized1e2ea0;
extern void* g_factoryTable1e2ea0[kTableCount];

class FactoryVisitor1e2ea0
{
public:
    virtual ~FactoryVisitor1e2ea0();
    virtual std::uint32_t Visit(void* a_factory) = 0;
};

struct Unit1e2ea0
{
    static void ForEachFactory1e2ea0(FactoryVisitor1e2ea0* a_visitor);  // compared: 0x1e2ea0
};
