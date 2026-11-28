// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x131fb0 Function131fb0
// Adapted bodies: none
#include "FreeFunction_131fb0.h"

// Destroys a contiguous range of std::function objects.
void Function131fb0(Func131fb0* a_first, Func131fb0* a_last)
{
    for (; a_first != a_last; ++a_first)
    {
        a_first->~Func131fb0();
    }
}
