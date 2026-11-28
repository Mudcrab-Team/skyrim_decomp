// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// FreeBuffer317c90, Obj317c90: GUESS(low)
#pragma once

#include <cstdint>

void FreeBuffer317c90(void* a_buffer);

class Obj317c90
{
public:
    Obj317c90();

    virtual ~Obj317c90()
    {
        FreeBuffer317c90(m_buffer);
    }

    void* m_buffer;       // 0x08
    std::uint64_t unk10;  // 0x10
    std::uint64_t unk18;  // 0x18
};
static_assert(sizeof(Obj317c90) == 0x20, "Obj317c90 size");
