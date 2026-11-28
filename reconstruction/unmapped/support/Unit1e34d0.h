// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Factory1e34d0, Unit1e34d0, g_tableInitialized1e34d0, g_factoryTable1e34d0, g_defaultName1e34d0, GetFactoryName1e34d0, Slot0, Slot1, GetName, kTableCount: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

constexpr std::size_t kTableCount = 138;

class Factory1e34d0
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual const char* GetName() const;
};

extern bool g_tableInitialized1e34d0;
extern Factory1e34d0* g_factoryTable1e34d0[kTableCount];
extern const char g_defaultName1e34d0[];

struct Unit1e34d0
{
    static const char* GetFactoryName1e34d0(std::uint8_t a_type);  // compared: 0x1e34d0
};
