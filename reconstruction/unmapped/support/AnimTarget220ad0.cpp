// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x220ad0 AnimTarget220ad0::FindTargetFlag
// Adapted bodies: none
#include "AnimTarget220ad0.h"

// Find a target entry by case-insensitive name and return its flag byte.
std::uint8_t AnimTarget220ad0::FindTargetFlag(const char* targetName, std::uint32_t* outIndex) const
{
    for (std::uint32_t i = 0; i < count; ++i)
    {
        const char* name = entries[i].name;
        if (name && _stricmp(name, targetName) == 0)
        {
            if (outIndex)
            {
                *outIndex = i;
            }
            return slots[i].flag19;
        }
    }
    return 0;
}
