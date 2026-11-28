// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// FreeBuffer3184f0, Obj3184f0: GUESS(low)
#pragma once

#include <cstdint>

void FreeBuffer3184f0(void* a_buffer);

class Obj3184f0
{
public:
    Obj3184f0();

    virtual ~Obj3184f0()
    {
        FreeBuffer3184f0(m_buffer);
    }

    void* m_buffer;       // 0x08
    std::uint64_t unk10;  // 0x10
};
static_assert(sizeof(Obj3184f0) == 0x18, "Obj3184f0 size");
