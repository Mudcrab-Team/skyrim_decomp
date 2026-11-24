// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: hkLargeBlockAllocator::Func00dd91f0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/memory/allocator/freelist/hklargeblockallocator.cpp:38
// 0xc59eb0 hkLargeBlockAllocator::Func00dd91f0
#include "Globals_c59eb0.h"

void hkLargeBlockAllocator::Func00dd91f0()
{
    m_p = (int*)&Data010d7c80;
    if (m_r)
        m_r->removeReference();
    m_p = (int*)&Data0102e388;
}
