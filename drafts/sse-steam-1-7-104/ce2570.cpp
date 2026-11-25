// Near miss: 11.5 alignment distance | other
// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0xce2570 BSTArrayAllocatorFunctor_gs_T1_ge_::Functionce2570

#include "include/ce2570/BSTArrayAllocatorFunctor_gs_T1_ge__ce2570.h"

// Accumulate a table-based checksum over the four bytes of a word.
void BSTArrayAllocatorFunctor_gs_T1_ge_::Functionce2570(std::uint32_t* result, std::uint32_t value)
{
    std::uint32_t crc = gWordChecksumTable[static_cast<std::uint8_t>(value)];
    crc = gWordChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 8))] ^ (crc >> 8);
    crc = gWordChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 16))] ^ (crc >> 8);
    crc = gWordChecksumTable[static_cast<std::uint8_t>(crc ^ (value >> 24))] ^ (crc >> 8);
    *result = crc;
}
