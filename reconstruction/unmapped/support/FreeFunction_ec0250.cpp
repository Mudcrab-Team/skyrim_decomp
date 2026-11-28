// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xec0250 Functionec0250
// Adapted bodies: none
#include "FreeFunction_ec0250.h"

// Invokes the Win32 handle call and returns 0 on success or 7 after querying GetLastError on failure.
std::uint32_t Functionec0250(void* handle)
{
    std::uint32_t status = WinCall_ec0250(handle) ? 0u : 7u;
    if (status != 0) {
        GetLastError();
    }
    return status;
}
