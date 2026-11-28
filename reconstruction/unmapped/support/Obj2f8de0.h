// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// FreeBuffer2f8de0, Obj2f8de0: GUESS(low)
#pragma once

#include <cstdint>

void FreeBuffer2f8de0(void* a_buffer);

class Obj2f8de0
{
public:
    Obj2f8de0();

    virtual ~Obj2f8de0()
    {
        FreeBuffer2f8de0(m_buffer);
    }

    void* m_buffer;       // 0x08
    std::uint64_t unk10;  // 0x10
};
static_assert(sizeof(Obj2f8de0) == 0x18, "Obj2f8de0 size");
