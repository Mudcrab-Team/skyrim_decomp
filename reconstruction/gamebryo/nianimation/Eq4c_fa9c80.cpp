// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Eq4c::Func00a4c890.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nilookatcontroller.cpp:840
// 0xfa9c80 Eq4c::Func00a4c890
#include "Eq4c_fa9c80.h"

bool Eq4c::Func00a4c890(Eq4c* other)
{
    if (!Func00a6cc80(other))
        return false;
    if ((m_spObj && !other->m_spObj) || (!m_spObj && other->m_spObj))
        return false;
    if (m_spObj && !m_spObj->IsEqual(other->m_spObj))
        return false;
    return true;
}
