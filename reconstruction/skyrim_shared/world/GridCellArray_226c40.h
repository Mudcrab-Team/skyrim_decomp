// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layouts for grid slot access and cell state.
// GridCellArray, TESObjectCELL, CellState, kAttached, cells, cellState, land3DAttached: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ResetCenter, GetCellSlot, IsCellAttached, GridCenter, position: GUESS(low)
// SetCenter, Detach, ClearItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "GridArray_226c60.h"

class TESObjectCELL
{
public:
    enum class CellState : std::uint8_t
    {
        kAttached = 7
    };

    std::uint8_t unknown00[0x44];
    CellState cellState;
};

struct GridCenter
{
    float x;
    float y;
    float z;
};

class GridCellArray : public GridArray
{
public:
    void ResetCenter();
    TESObjectCELL** GetCellSlot(std::uint32_t x, std::uint32_t y) const;
    bool SetCenter(std::int32_t x, std::int32_t y) override;

    // These operations require coordinates inside the current grid.
    bool IsCellAttached(std::uint32_t x, std::uint32_t y) const;
    void ClearItem(std::uint32_t x, std::uint32_t y) override;

private:
    TESObjectCELL** cells;
    GridCenter position;
    bool land3DAttached;
};

static_assert(sizeof(GridCellArray) == 0x30, "cell grid size");
