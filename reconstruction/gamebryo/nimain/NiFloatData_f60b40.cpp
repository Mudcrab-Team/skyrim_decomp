// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00a3cd40_cls::Func00a3cd40.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:290
// 0xf60b40 Func00a3cd40_cls::Func00a3cd40
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:159
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:165
// Adapted helpers: Write, GetWriter
#include "NiFloatData_f60b40.h"

bool Func00a3cd40_cls::Func00a3cd40(NiFloatData* other)
{
    if (!IsSameAs(other))
    {
        return false;
    }
    if (m_uiNumKeys != other->m_uiNumKeys)
    {
        return false;
    }
    if (m_eRequestType != other->m_eRequestType)
    {
        return false;
    }
    if (m_ucKeyDataSize != other->m_ucKeyDataSize)
    {
        return false;
    }
    Func00a3cd40_KeyCmp cmp = Data011f3ae0[m_eRequestType];
    unsigned int iKeyIndex = 0;
    if (m_uiNumKeys > 0)
    {
        do
        {
            void* a = (char*)other->m_pKeyArray + (unsigned int)m_ucKeyDataSize * iKeyIndex;
            void* n = (char*)m_pKeyArray + (unsigned int)m_ucKeyDataSize * iKeyIndex;
            if (!cmp(n, a))
            {
                return false;
            }
            ++iKeyIndex;
        } while (iKeyIndex < m_uiNumKeys);
    }
    return true;
}
