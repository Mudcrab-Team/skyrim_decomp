// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00cf6330.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp:234
// 0xaa90c0 Func00cf6330
#include "Globals_aa90c0.h"

hkBool Func00cf6330(const Container* apContainer)
{
    int n = apContainer->Func00d46f70();
    for (int i = 0; i < n; i++)
    {
        if (!GetFlagByState(apContainer->Func00d46f80(i)))
            return false;
    }
    return true;
}
