// Exposure detail: (community PDB layout; pinned-image observations).
// Source exposure: mixed
// Code origin: original.
// SPDX-License-Identifier: CC0-1.0
// NiTriShapeData, triList: CRASHLOGGER_PDB(59818@2026.10.24)
// NiTriShapeData::Functionf17880, unknown00: GUESS(low)

#pragma once
#include <cstdint>
#include <cstddef>

class NiTriShapeData
{
public:
    void Functionf17880(std::uint16_t triangle, std::uint16_t* first,
                       std::uint16_t* second, std::uint16_t* third);
    std::uint8_t unknown00[0x78];
    std::uint16_t* triList;
};
static_assert(offsetof(NiTriShapeData, triList) == 0x78, "triangle list offset");
