// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: NiFloatController::IsEqual.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nifloatcontroller.cpp:449
// 0xf98320 NiFloatController::IsEqual
#include "NiFloatController_f98320.h"

bool NiFloatController::IsEqual(NiFloatController* other)
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
