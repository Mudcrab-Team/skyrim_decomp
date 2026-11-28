// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x12b2b60 Function12b2b60
// Adapted bodies: none
#include "FreeFunction_12b2b60.h"

// Looks up key in g_map_12b2b60 under g_lock_12b2b60 and returns the mapped pointer or null.
void* Function12b2b60(std::uint64_t key)
{
    EnterCriticalSection(&g_lock_12b2b60);
    void* value = nullptr;
    std::map<std::uint64_t, void*>::iterator it = g_map_12b2b60.find(key);
    if (it != g_map_12b2b60.end()) {
        value = it->second;
    }
    LeaveCriticalSection(&g_lock_12b2b60);
    return value;
}
