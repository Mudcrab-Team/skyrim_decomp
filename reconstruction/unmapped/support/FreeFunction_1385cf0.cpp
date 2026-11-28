// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x1385cf0 Function1385cf0
// Adapted bodies: none
#include "FreeFunction_1385cf0.h"

// Waits indefinitely for an OS handle if present, closes it, and clears the stored handle.
void Function1385cf0(ThreadHolder1385cf0* a_holder)
{
    if (a_holder->handle) {
        WaitForSingleObject(a_holder->handle, 0xFFFFFFFFu);
        CloseHandle(a_holder->handle);
        a_holder->handle = nullptr;
    }
}
