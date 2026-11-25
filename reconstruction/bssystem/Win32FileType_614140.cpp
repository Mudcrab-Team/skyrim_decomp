// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original; handwritten from pinned-image behavior
// SPDX-License-Identifier: CC0-1.0
// 0x614140 Win32FileType::Function614140
// Adapted bodies: none
#include "Win32FileType_614140.h"

std::uint32_t Win32FileType::Function614140(const void* buffer, std::uint32_t size)
{
    std::uint32_t written = 1;
    std::uint32_t result = writeCallback(this, buffer, size, &written, 1);
    position += result;
    return result;
}
