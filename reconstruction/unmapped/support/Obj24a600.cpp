// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x24a600 Obj24a600::Lookup
// Adapted bodies: none
#include "Obj24a600.h"

// Search the global entry array for a matching key and write its value if found.
bool Obj24a600::Lookup(std::uint32_t* outValue) const
{
    bool found = false;
    for (std::uint32_t i = 0; i < g_entryCount && !found; ++i)
    {
        found = (g_entries24a600[i].key == key);
        if (found)
        {
            *outValue = g_entries24a600[i].value;
        }
    }
    return found;
}
