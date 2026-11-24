// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00a57100_Caller::Func00a57100.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niextradatacontroller.cpp:59
// 0x109c9f0 Func00a57100_Caller::Func00a57100
#include "Func00a57100_Caller_109c9f0.h"

bool Func00a57100_Caller::Func00a57100(NiStream& kStream)
{
    if (!((BaseFake*)this)->RegisterInterpolatorStreamables(kStream))
        return false;
    ((StreamVTable*)&kStream)->f8((void*)((char*)this + 0x10));
    return true;
}
