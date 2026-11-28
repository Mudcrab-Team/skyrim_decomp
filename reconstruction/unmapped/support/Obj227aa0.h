// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj227aa0::RemoveMatchingCells, treated as adapted: shaped like GridArray::DetachAll in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/gridarray.cpp:16
// SPDX-License-Identifier: CC0-1.0
// Obj227aa0, Vfunc00, Vfunc08, Vfunc10, Vfunc18, Vfunc20, Vfunc28, OnCellMatch, RemoveMatchingCells, GetCell, unk08, dimension, cells: GUESS(low)
#pragma once

#include <cstdint>

class Obj227aa0
{
public:
    virtual void Vfunc00();
    virtual void Vfunc08();
    virtual void Vfunc10();
    virtual void Vfunc18();
    virtual void Vfunc20();
    virtual void Vfunc28();
    virtual void OnCellMatch(std::uint32_t row, std::uint32_t col);

    void RemoveMatchingCells(void* target);

    void** GetCell(std::uint32_t row, std::uint32_t col) const
    {
        if (row < dimension && col < dimension)
        {
            return &cells[row * dimension + col];
        }
        return nullptr;
    }

    std::uint64_t unk08;      // 08
    std::uint32_t dimension;  // 10
    void** cells;             // 18
};
