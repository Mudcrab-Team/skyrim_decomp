// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x1317c0 FuncVector1317c0::DestroyRange
// Adapted bodies: none
#include "FuncVector1317c0.h"

// Destroys a contiguous range of std::function objects.
// guess: a container member that needs only its arguments; the call does not read this.
void FuncVector1317c0::DestroyRange(Func1317c0* a_first, Func1317c0* a_last)
{
    for (; a_first != a_last; ++a_first)
    {
        a_first->~Func1317c0();
    }
}
