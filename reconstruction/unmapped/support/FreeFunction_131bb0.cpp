// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x131bb0 Function131bb0
// Adapted bodies: none
#include "FreeFunction_131bb0.h"

// Destroys a contiguous range of std::function objects.
void Function131bb0(Func131bb0* a_first, Func131bb0* a_last)
{
    for (; a_first != a_last; ++a_first)
    {
        a_first->~Func131bb0();
    }
}
