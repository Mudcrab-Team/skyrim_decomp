// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x443320 Function443320
// Cookbook: 0x443320 35
// Adapted bodies: none
#include "FreeFunction_443320.h"

// Looks up an actor value index (0..163) by case-insensitive name, returning 164 if not found.
// The community name table calls this GetActorValueIdFromName (a hint, not proof); the names in this unit are stand-ins.
std::int32_t Function443320(const char* name)
{
    std::int32_t result = 164;
    for (std::int32_t i = 0; i < 164 && result == 164; ++i) {
        const char* entryName = g_actorValueTable443320->entries[i]->name;
        if (_stricmp(entryName, name) == 0) {
            result = i;
        }
    }
    return result;
}
