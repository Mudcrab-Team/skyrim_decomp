// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// UI_element140860: GUESS(low)
// InfiniteList140860: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

// guess: stand-in; the CrashLogger PDB names the destructor call UI_element::~UI_element, and the size includes any middle base.
struct UI_element140860
{
    virtual ~UI_element140860();

    std::uint8_t unk08[0x50];
};

static_assert(sizeof(UI_element140860) == 0x58, "UI_element140860 size");

struct InfiniteList140860 : UI_element140860
{
    InfiniteList140860();
    ~InfiniteList140860() override
    {
    }

    std::vector<void*> entries;
    std::uint8_t unk70[0x20];
};

static_assert(sizeof(InfiniteList140860) == 0x90, "InfiniteList140860 size");
