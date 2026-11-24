// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Partition::GetStripIndexCount.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niskinpartition.cpp:11
// 0xf08160 Partition::GetStripIndexCount
#include "Partition_f08160.h"

unsigned int NiSkinPartition::Partition::GetStripIndexCount()
{
    unsigned int sum = 0;
    for (unsigned int i = 0; i < m_usStrips; ++i)
        sum += m_pusStripLengths[i];
    return sum;
}
