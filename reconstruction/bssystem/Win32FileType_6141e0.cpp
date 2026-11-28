// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x6141e0 Win32FileType::sub_1405790E0
#include "Win32FileType_6141e0.h"

// Write a 1-, 2-, or 4-byte integer value through the file callback and advance the byte counter.
void Win32FileType::sub_1405790E0(std::uint32_t a_value, std::uint32_t a_sizeType)
{
    switch (a_sizeType) {
    case 0: {
        std::uint8_t val = static_cast<std::uint8_t>(a_value);
        std::uint32_t count = 1;
        bytesWritten += writeFn(this, &val, 1, &count, 1);
        break;
    }
    case 1: {
        std::uint16_t val = static_cast<std::uint16_t>(a_value);
        std::uint32_t count = 1;
        bytesWritten += writeFn(this, &val, 2, &count, 1);
        break;
    }
    case 2: {
        std::uint32_t count = 1;
        bytesWritten += writeFn(this, &a_value, 4, &count, 1);
        break;
    }
    default:
        break;
    }
}
