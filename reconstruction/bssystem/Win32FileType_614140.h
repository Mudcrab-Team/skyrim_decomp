// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original; handwritten from pinned-image behavior
// SPDX-License-Identifier: CC0-1.0
// Win32FileType: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN; receiver identity unproven
// Function614140, position, writeCallback, unknown00, unknown0c, unknown10: GUESS(low) STANDIN; observed accesses
#pragma once
#include <cstddef>
#include <cstdint>

class Win32FileType
{
public:
    std::uint32_t Function614140(const void* buffer, std::uint32_t size);
    void* unknown00;
    std::uint32_t position;
    std::uint32_t unknown0c;
    void* unknown10;
    std::uint32_t (*writeCallback)(Win32FileType*, const void*, std::uint32_t,
                                   std::uint32_t*, std::uint32_t);
};
static_assert(offsetof(Win32FileType, position) == 0x8, "observed position offset");
static_assert(offsetof(Win32FileType, writeCallback) == 0x18, "observed callback offset");
