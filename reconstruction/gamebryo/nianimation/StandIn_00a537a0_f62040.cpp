// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: StandIn_00a537a0::Func00a537a0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nibooldata.cpp:55
// 0xf62040 StandIn_00a537a0::Func00a537a0
#include "StandIn_00a537a0_f62040.h"

void StandIn_00a537a0::Func00a537a0(float m_fStartTime, float m_fMaximumDistance)
{
    void* pkKeys = m_pKeyArray;
    UpdateSlotStates(3, m_eRequestType, pkKeys, m_uiNumKeys, m_fStartTime, m_fMaximumDistance);
    m_pKeyArray = pkKeys;
}
