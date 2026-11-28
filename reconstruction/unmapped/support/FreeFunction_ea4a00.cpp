// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xea4a00 Functionea4a00
// Adapted bodies: none
#include "FreeFunction_ea4a00.h"

// Enters the global critical section when initialized, or returns 0x80010002 otherwise.
std::uint32_t Functionea4a00()
{
    if (g_initialized_ea4a00) {
        EnterCriticalSection(&g_lock_ea4a00);
        return 0;
    }
    return 0x80010002u;
}
