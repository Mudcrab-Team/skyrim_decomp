// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: ProcessChildLoop.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/physics/dynamics/world/util/hkpworldmemoryutil.cpp:250
// 0xb7c4a0 ProcessChildLoop
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/havok/physics/dynamics/world/util/hkpworldmemoryutil.cpp:261
#include "Globals_b7c4a0.h"

void ProcessChildLoop(ParamObj* param)
{
    if (param->Func00c93570() == 0)
    {
        return;
    }

    int i = 10;
    while (param->m_08->m_28 != 0)
    {
        if (i-- <= 0)
        {
            break;
        }

        InnerObj* inner = param->Func00c93570();
        inner->v10(param);
        Func00d88040(0);
        ApplyActionPhases(param);
    }
}
