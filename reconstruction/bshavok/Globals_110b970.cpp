// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: ClearFlagsAndMarkDirty.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpusplitsimulationislandjob.cpp:35
// 0x110b970 ClearFlagsAndMarkDirty
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/physics/dynamics/world/simulation/multithreaded/cpu/hkpcpusplitsimulationislandjob.cpp:39
#include "Globals_110b970.h"

void ClearFlagsAndMarkDirty(D942F0Island* island, void* context)
{
    island->m_flags &= ~3;
    D942F0Array entities;
    island->markDirty();
    Func00cb6060(island, island->m_pOwningWorld, context, &entities);
}
