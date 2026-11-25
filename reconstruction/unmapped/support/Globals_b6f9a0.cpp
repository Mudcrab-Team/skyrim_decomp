// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkpPhantom::Routine140A913B0.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00d00000_o2.cpp:217
// 0xb6f9a0 hkpPhantom::Routine140A913B0
#include "Globals_b6f9a0.h"

void hkpPhantom::Routine140A913B0()
{
    for (int i = m_9C - 1; i >= 0; --i)
    {
        Func00d07910_elem** ppSlot = &m_98[i];
        if (m_98[i] != 0)
        {
            Func00d07910_elem* e = *ppSlot;
            e->v10(this);
        }
    }
}
