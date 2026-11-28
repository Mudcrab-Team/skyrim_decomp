// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xec0710 BSSystemFileec0710::DoGetSize
// Adapted bodies: none
#include "BSSystemFileec0710.h"

// Queries the Win32 file size for handle, writing *outSize and returning 0 on success or 7 on failure.
std::uint32_t BSSystemFileec0710::DoGetSize(std::uint64_t* outSize)
{
    std::uint64_t fileSize;
    if (GetFileSizeEx(handle, &fileSize) != 0) {
        *outSize = fileSize;
        return 0;
    }
    *outSize = 0;
    return 7;
}
