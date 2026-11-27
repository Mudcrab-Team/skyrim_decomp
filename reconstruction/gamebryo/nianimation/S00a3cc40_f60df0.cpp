// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: S00a3cc40::Func00a3cc40.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nifloatdata.cpp:57
// 0xf60df0 S00a3cc40::Func00a3cc40
#include "S00a3cc40_f60df0.h"

void S00a3cc40::Func00a3cc40(float m_fStartTime, float m_fMaximumDistance)
{
    void* pkKeys = m_pKeyArray;
    UpdateSlotStates(0, m_eRequestType, &pkKeys, &m_uiNumKeys, m_fStartTime, m_fMaximumDistance);
    m_pKeyArray = pkKeys;
}
