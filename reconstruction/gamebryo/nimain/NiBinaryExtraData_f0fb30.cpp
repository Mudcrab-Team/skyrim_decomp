// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiBinaryExtraData::IsEqual.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nibinaryextradata.cpp:394
// 0xf0fb30 NiBinaryExtraData::IsEqual
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nibinaryextradata.cpp:188
#include "NiBinaryExtraData_f0fb30.h"

bool NiBinaryExtraData::IsEqual(const NiBinaryExtraData* pkOther) const
{
    if (!pkOther)
        return false;
    if (m_uiSize != pkOther->m_uiSize)
        return false;
    if (memcmp(m_pByteBuffer, pkOther->m_pByteBuffer, m_uiSize) != 0)
        return false;
    return true;
}
