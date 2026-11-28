// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x24a450 Obj24a450::Lookup
// Adapted bodies: none
#include "Obj24a450.h"

// Search the global entry array for a matching key and copy its value.
bool Obj24a450::Lookup(std::uint32_t* outValue) const
{
    bool found = false;
    if (g_tableReady)
    {
        for (std::uint32_t i = 0; i < g_entryCount && !found; ++i)
        {
            found = (g_entries24a450[i].key == key);
            *outValue = g_entries24a450[i].value;
        }
    }
    return found;
}
