// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1516b0 Function1516b0
// Adapted bodies: none
#include "FreeFunction_1516b0.h"

// Checks whether any entry's effect maps to a table record whose kind equals 0x2B.
bool Function1516b0(const EffectOwner1516b0* owner)
{
    for (std::uint32_t i = 0; i < owner->count; ++i)
    {
        const EffectEntry1516b0* entry = owner->entries[i];
        if (entry != nullptr && entry->effect != nullptr)
        {
            if (gEffectTable1516b0[entry->effect->tableIndex].kind == 0x2B)
            {
                return true;
            }
        }
    }
    return false;
}
