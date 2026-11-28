// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x151420 Function151420
// Adapted bodies: none
#include "FreeFunction_151420.h"

// Checks whether owner contains an entry pointing to target with bit 0 of flags6B clear.
bool Function151420(const EffectOwner151420* owner, const EffectTarget151420* target)
{
    bool found = false;
    for (std::uint32_t i = 0; i < owner->count && !found; ++i)
    {
        const EffectEntry151420* entry = owner->entries[i];
        if (entry != nullptr && entry->target == target)
        {
            if ((entry->target->flags6B & 0x1) == 0)
            {
                found = true;
            }
        }
    }
    return found;
}
