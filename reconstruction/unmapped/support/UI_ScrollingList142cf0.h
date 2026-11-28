// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// UI_element142cf0: GUESS(low)
// UI_ScrollingList142cf0: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

// guess: stand-in; the CrashLogger PDB names the destructor call UI_element::~UI_element, and the size includes any middle base.
struct UI_element142cf0
{
    virtual ~UI_element142cf0();

    std::uint8_t unk08[0x98];
};

static_assert(sizeof(UI_element142cf0) == 0xA0, "UI_element142cf0 size");

struct UI_ScrollingList142cf0 : UI_element142cf0
{
    UI_ScrollingList142cf0();
    ~UI_ScrollingList142cf0() override
    {
    }

    std::vector<void*> entries;
    std::uint8_t unkB8[0x48];
};

static_assert(sizeof(UI_ScrollingList142cf0) == 0x100, "UI_ScrollingList142cf0 size");
