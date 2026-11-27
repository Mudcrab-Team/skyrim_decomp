// Source exposure: mixed
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CRC32Calculator, CRC32Calculator::SizeOf64: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// gWideChecksumTable: GUESS(low)

#pragma once

#include <cstdint>

extern const std::uint32_t gWideChecksumTable[256];

class CRC32Calculator
{
public:
    static void SizeOf64(std::uint32_t* result, std::uint64_t value);
};
