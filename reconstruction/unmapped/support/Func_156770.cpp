// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x156770 Func_156770::CacheEntry
// Adapted bodies: none
#include "Func_156770.h"

#include <cstring>

// Clears the thread-local cache on owner change and stores entry at its slot index.
void Func_156770::CacheEntry(void* owner, Entry156770* entry)
{
    if (!owner || !entry)
    {
        return;
    }
    if (owner != g_tlsOwner156770_tls_0x18)
    {
        std::memset(g_tlsSlots156770_tls_0x20, 0, sizeof(g_tlsSlots156770_tls_0x20));
        g_tlsOwner156770_tls_0x18 = owner;
    }
    g_tlsSlots156770_tls_0x20[entry->GetSlotIndex()] = entry;
}
