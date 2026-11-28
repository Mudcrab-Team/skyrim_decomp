// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Win32FileType, Win32FileType::sub_1405790E0: CRASHLOGGER_PDB(59818@2026.10.24)
// WriteCallback, bytesWritten, writeFn: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Win32FileType;
using WriteCallback = std::uint32_t (*)(Win32FileType*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

class Win32FileType
{
public:
    void sub_1405790E0(std::uint32_t a_value, std::uint32_t a_sizeType);  // compared: 0x6141e0

    std::uint8_t  unk00[0x08];  // 00
    std::uint32_t bytesWritten; // 08
    std::uint8_t  unk0C[0x0C];  // 0C
    WriteCallback writeFn;      // 18
};
static_assert(offsetof(Win32FileType, bytesWritten) == 0x08, "bytesWritten offset");
static_assert(offsetof(Win32FileType, writeFn) == 0x18, "writeFn offset");
