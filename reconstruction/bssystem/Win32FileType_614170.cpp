// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original; handwritten from pinned-image behavior
// SPDX-License-Identifier: CC0-1.0
// 0x614170 Win32FileType::Function614170
// Adapted bodies: none
#include "Win32FileType_614170.h"

std::uint32_t Win32FileType::Function614170(void* buffer, std::uint32_t size)
{
    std::uint32_t read = 1;
    std::uint32_t result = readCallback(this, buffer, size, &read, 1);
    position += result;
    return result;
}
