// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original; the pinned image listing and CrashLogger PDB names
// SPDX-License-Identifier: CC0-1.0
// FreeBuffer3184a0, Obj3184a0: GUESS(low)
#pragma once

#include <cstdint>

void FreeBuffer3184a0(void* a_buffer);

class Obj3184a0
{
public:
    Obj3184a0();

    virtual ~Obj3184a0()
    {
        FreeBuffer3184a0(m_buffer);
    }

    void* m_buffer;       // 0x08
    std::uint64_t unk10;  // 0x10
};
static_assert(sizeof(Obj3184a0) == 0x18, "Obj3184a0 size");
