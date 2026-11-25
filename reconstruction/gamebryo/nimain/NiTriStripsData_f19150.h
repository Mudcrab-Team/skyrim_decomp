// Source exposure: mixed (community layout; pinned-image observations; permitted sibling declarations).
// Code origin: original; declarations and naming sources labelled below
// SPDX-License-Identifier: CC0-1.0
// NiTriStripsData, numTriangles, numStrips, stripLengths, stripLists: CRASHLOGGER_PDB(59818@2026.10.24)
// NiTriStripsData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); partial layout preserving accessed fields.
// NiTriStripsData::GetTriangleStripData: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
#pragma once

#include <cstddef>
#include <cstdint>

class NiTriStripsData
{
public:
    void GetTriangleStripData(std::uint16_t& strips, const std::uint16_t*& lengths,
        const std::uint16_t*& lists, std::uint32_t& lengthSum);

    std::uint8_t unknown00[0x68];
    std::uint16_t numTriangles;  // 0x68
    std::uint8_t unknown6a[6];
    std::uint16_t numStrips;  // 0x70
    std::uint8_t unknown72[6];
    std::uint16_t* stripLengths;  // 0x78
    std::uint16_t* stripLists;  // 0x80
};
static_assert(offsetof(NiTriStripsData, numTriangles) == 0x68, "triangle count offset");
static_assert(offsetof(NiTriStripsData, numStrips) == 0x70, "strip count offset");
static_assert(offsetof(NiTriStripsData, stripLengths) == 0x78, "strip lengths offset");
static_assert(offsetof(NiTriStripsData, stripLists) == 0x80, "strip lists offset");
