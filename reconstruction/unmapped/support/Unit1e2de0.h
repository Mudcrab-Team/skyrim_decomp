// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Unit1e2de0, g_tableInitialized1e2de0, g_factoryTable1e2de0, RegisterFactory1e2de0, kTableCount: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

constexpr std::size_t kTableCount = 138;

extern bool g_tableInitialized1e2de0;
extern void* g_factoryTable1e2de0[kTableCount];

struct Unit1e2de0
{
    static void RegisterFactory1e2de0(std::uint8_t a_type, void* a_factory);  // compared: 0x1e2de0
};
