// Source exposure: mixed (community layout; pinned-image observations; permitted sibling declarations).
// Code origin: original; handwritten from observed field accesses and output widths
// SPDX-License-Identifier: CC0-1.0
// 0xf19150 NiTriStripsData::GetTriangleStripData
// Adapted bodies: none
#include "NiTriStripsData_f19150.h"

// Returns the strip arrays and their element counts.
void NiTriStripsData::GetTriangleStripData(std::uint16_t& strips,
    const std::uint16_t*& lengths, const std::uint16_t*& lists, std::uint32_t& lengthSum)
{
    strips = numStrips;
    lengths = stripLengths;
    lists = stripLists;
    lengthSum = static_cast<std::uint16_t>(numTriangles + 2 * numStrips);
}
