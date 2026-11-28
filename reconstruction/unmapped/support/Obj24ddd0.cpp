// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x24ddd0 Obj24ddd0::WaitAndReset
// Adapted bodies: none
#include "Obj24ddd0.h"

// Clamp pending wait time to 20 ms, sleep, and reset the counter.
void Obj24ddd0::WaitAndReset()
{
    if (g_waitCount != 0)
    {
        if (g_waitCount > 20)
        {
            g_waitCount = 20;
        }
        Sleep(g_waitCount);
        g_waitCount = 0;
    }
}
