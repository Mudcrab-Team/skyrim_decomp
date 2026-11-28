// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj227aa0::RemoveMatchingCells, treated as adapted: shaped like GridArray::DetachAll in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/gridarray.cpp:16
// SPDX-License-Identifier: CC0-1.0
// 0x227aa0 Obj227aa0::RemoveMatchingCells
#include "Obj227aa0.h"

// Notify virtual handler for every grid cell pointing to the target object.
void Obj227aa0::RemoveMatchingCells(void* target)
{
    for (std::uint32_t row = 0; row < dimension; ++row)
    {
        for (std::uint32_t col = 0; col < dimension; ++col)
        {
            if (*GetCell(row, col) == target)
            {
                OnCellMatch(row, col);
            }
        }
    }
}
