// Near miss: 2.0 alignment distance | register-schedule
// Exposure detail: (community PDB layout; pinned-image observations).
// Source exposure: mixed
// Code origin: original.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none.
// 0xf17880 NiTriShapeData::Functionf17880

#include "include/f17880/NiTriShapeData_f17880.h"

void NiTriShapeData::Functionf17880(std::uint16_t triangle, std::uint16_t* first,
                                  std::uint16_t* second, std::uint16_t* third)
{
    std::uint16_t* indices = triList;
    std::uint32_t index = 3 * triangle;
    *first = indices[index++];
    *second = indices[index++];
    *third = indices[index];
}
