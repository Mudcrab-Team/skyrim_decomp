// Near miss: 22.0 alignment distance | other
// Source exposure: mixed
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// CRC32Calculator, CRC32Calculator::SizeOf64: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// gWideChecksumTable: GUESS(low)
// 0xce25f0 CRC32Calculator::SizeOf64

#include "include/ce25f0/CRC32Calculator_ce25f0.h"

// Compute the table-based checksum of a 64-bit value.
void CRC32Calculator::SizeOf64(std::uint32_t* result, std::uint64_t value)
{
    std::uint64_t crc = gWideChecksumTable[static_cast<std::uint8_t>(value)];
    crc = gWideChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 8))] ^ (crc >> 8);
    crc = gWideChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 16))] ^ (crc >> 8);
    crc = gWideChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 24))] ^ (crc >> 8);
    crc = gWideChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 32))] ^ (crc >> 8);
    crc = gWideChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 40))] ^ (crc >> 8);
    crc = gWideChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 48))] ^ (crc >> 8);
    crc = gWideChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 56))] ^ (crc >> 8);
    *result = static_cast<std::uint32_t>(crc);
}
