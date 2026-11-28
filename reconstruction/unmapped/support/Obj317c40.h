// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// FreeBuffer317c40, Obj317c40: GUESS(low)
#pragma once

#include <cstdint>

void FreeBuffer317c40(void* a_buffer);

class Obj317c40
{
public:
    Obj317c40();

    virtual ~Obj317c40()
    {
        FreeBuffer317c40(m_buffer);
    }

    void* m_buffer;       // 0x08
    std::uint64_t unk10;  // 0x10
    std::uint64_t unk18;  // 0x18
};
static_assert(sizeof(Obj317c40) == 0x20, "Obj317c40 size");
