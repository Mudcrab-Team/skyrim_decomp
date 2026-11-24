// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: ResetEntryAgents.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00d20000_o2.cpp:1306
// 0xc2e960 ResetEntryAgents
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00d20000_o2.cpp:1358
#include "Globals_c2e960.h"

D3FE10Entry* ResetEntryAgents(D3FE10Header* pkHeader, D3FE10Entry* pkEntry, D3FE10Manager* pkManager, void* pkInfo)
{
    for (int i = 0; i < pkEntry->m_numAgents; i++) {
        unsigned short id = pkEntry->m_pAgents[i].m_iOwnerObjectOffset;
        if (id != 0xffff)
            pkManager->ResetAgent(id, pkInfo);
    }
    pkEntry->m_numAgents = 0;
    pkHeader->m_iNumberOfEntries = 0;
    return pkEntry + 1;
}
