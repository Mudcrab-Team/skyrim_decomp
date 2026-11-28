// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// UI_element1453c0: GUESS(low)
// MidBase1453c0: GUESS(low)
// UI_bannerEntry1453c0: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

// guess: stand-in; the CrashLogger PDB names the destructor call UI_element::~UI_element, and the size includes any middle base.
struct UI_element1453c0
{
    virtual ~UI_element1453c0();

    std::uint8_t unk08[0x148];
};

struct MidBase1453c0 : UI_element1453c0
{
    ~MidBase1453c0() override
    {
    }
};

static_assert(sizeof(MidBase1453c0) == 0x150, "MidBase1453c0 size");

struct UI_bannerEntry1453c0 : MidBase1453c0
{
    UI_bannerEntry1453c0();
    ~UI_bannerEntry1453c0() override
    {
    }

    std::vector<void*> entries;
    std::uint8_t unk168[0x10];
};

static_assert(sizeof(UI_bannerEntry1453c0) == 0x178, "UI_bannerEntry1453c0 size");
