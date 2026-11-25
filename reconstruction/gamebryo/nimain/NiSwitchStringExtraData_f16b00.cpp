// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiSwitchStringExtraData::IsEqual.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niswitchstringextradata.cpp:264
// 0xf16b00 NiSwitchStringExtraData::IsEqual
#include "NiSwitchStringExtraData_f16b00.h"

bool NiSwitchStringExtraData::IsEqual(NiSwitchStringExtraData* pkOther)
{
    if (!pkOther)
        return false;
    if (m_uiSize != pkOther->m_uiSize)
        return false;
    if (m_iType != pkOther->m_iType)
        return false;
    if ((m_ppcStrings && !pkOther->m_ppcStrings) || (!m_ppcStrings && pkOther->m_ppcStrings))
        return false;
    if (m_ppcStrings)
    {
        for (unsigned int i = 0; i < m_uiSize; i++)
        {
            if ((m_ppcStrings[i] && !pkOther->m_ppcStrings[i]) || (!m_ppcStrings[i] && pkOther->m_ppcStrings[i]))
                return false;
            if (m_ppcStrings[i] && strcmp(m_ppcStrings[i], pkOther->m_ppcStrings[i]) != 0)
                return false;
        }
    }
    return true;
}
