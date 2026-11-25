// Source exposure: mixed (community declarations; local target observations).
// Code origin: original; target behavior and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// 0x1a9350 TES::SetNavMeshInfoMap
// Adapted bodies: none.
// NavMeshMemoryScope, previous: GUESS(low); restore the caller's allocation context on every exit
#include "TES_1a9350.h"
class NavMeshMemoryScope
{
public:
    NavMeshMemoryScope() : previous(g_memoryContext_tls_0x768)
    {
        g_memoryContext_tls_0x768 = 77;
    }
    ~NavMeshMemoryScope()
    {
        g_memoryContext_tls_0x768 = previous;
    }
private:
    std::uint32_t previous;
};
void TES::SetNavMeshInfoMap(NavMeshInfoMap* map)
{
    if (unk2B0)
    {
        NavMeshMemoryScope scope;
        delete unk2B0;
    }
    unk2B0 = map;
}
