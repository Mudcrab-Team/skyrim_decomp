// Source exposure: mixed (community declarations; CrashLogger names/layout; pinned-image observations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0xf19190 NiTriStripsData::GetBlockAllocationSize
// NiTriStripsData::GetBlockAllocationSize: CRASHLOGGER_PDB(59818@2026.10.24)
// Adapted bodies: none.
#include "NiTriStripsData_f19190.h"

std::uint32_t NiTriStripsData::GetBlockAllocationSize() const
{
    const std::uint16_t stripListLength = numTriangles + 2 * numStrips;
    const std::uint32_t stripStorage = 2 * (stripListLength + numStrips);
    return NiObject::GetBlockAllocationSize() + stripStorage;
}
