// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00a57b20_cls::Func00a57b20.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nifloatcontroller.cpp:449
// 0xfaa3d0 Func00a57b20_cls::Func00a57b20
#include "NiPSysColorModifier_faa3d0.h"

bool Func00a57b20_cls::Func00a57b20(Func00a57b20_cls* other)
{
    if (!Func00a6cc80(other))
    {
        return false;
    }
    Iface57b20* pInterface = m_38;
    void* pOtherInterface = other->m_38;
    unsigned char bResult = pInterface->v23(pOtherInterface);
    if (bResult != 0)
    {
        return true;
    }
    return false;
}
