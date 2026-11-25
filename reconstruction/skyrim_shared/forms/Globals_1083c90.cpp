// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: bhkConvexShape::SaveBinary_140DDD700.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesobjectrefr_o2_variant.cpp:5657
// 0x1083c90 bhkConvexShape::SaveBinary_140DDD700
#include "Globals_1083c90.h"

void bhkConvexShape::SaveBinary_140DDD700(C9FC00Stream& kStream)
{
    bool bValid;
    C9FC00Data* pkData = GetData(&bValid);
    if (kStream.m_ucEndian != 1)
        // Byte-swap intrinsic: the target code swaps the field with a bswap instruction.
        pkData->m_ulValue = _byteswap_ulong(pkData->m_ulValue);
    SaveBinaryBase(kStream);
    if (kStream.m_ucEndian != 1)
        // Byte-swap intrinsic: the target code swaps the field with a bswap instruction.
        pkData->m_ulValue = _byteswap_ulong(pkData->m_ulValue);
}
