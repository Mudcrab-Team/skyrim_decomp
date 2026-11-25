// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: StructArrayImplementation::reserve.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/collide/agent/compoundagent/shapecollection/hkpshapecollectionagent.cpp:60
// 0xc62610 StructArrayImplementation::reserve
#include "StructArrayImplementation_c62610.h"

void StructArrayImplementation::reserve(int arg)
{
    int i = 0;
    if (m_uiItemCount > 0)
    {
        do
        {
            m_entries[i].m_pInventoryEntryData->v09(arg);
            ++i;
        } while (i < m_uiItemCount);
    }
}
