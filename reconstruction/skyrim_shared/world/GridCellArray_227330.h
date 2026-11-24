// Source exposure: mixed
// Code origin: declarations and inline helpers reconstructed from the pinned image and sources cited in the companion source file.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GridCellArray, GridCellArray::Detach, GridCellArray::ClearItem, GridCellArray::cells, GridArray::length: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL::Detach: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// GridArray::GetGridDimension: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// GetCellSlot, unkSlot00, unkSlot01, unkSlot02, unkSlot03, unkSlot04, unkGrid08, unkGrid14: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class TESObjectCELL
{
public:
    void Detach(bool a_detach);
};

class GridCellArray
{
public:
    virtual void unkSlot00();
    virtual void unkSlot01();
    virtual void unkSlot02();
    virtual void unkSlot03();
    virtual void unkSlot04();
    virtual void Detach(std::uint32_t a_x, std::uint32_t a_y);
    virtual void ClearItem(std::uint32_t a_x, std::uint32_t a_y);

    std::uint32_t GetGridDimension() const { return length; }

    TESObjectCELL** GetCellSlot(std::uint32_t a_x, std::uint32_t a_y) const
    {
        const std::uint32_t dimension = GetGridDimension();
        if (a_x >= dimension || a_y >= dimension) {
            return nullptr;
        }
        return &cells[GetGridDimension() * a_x + a_y];
    }

    unsigned char unkGrid08[8];
    std::uint32_t length;
    std::uint32_t unkGrid14;
    TESObjectCELL** cells;
};

static_assert(offsetof(GridCellArray, cells) == 0x18, "Grid storage offset");
