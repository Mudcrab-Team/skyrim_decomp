// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GridCell.cpp:210
// GridArray, GridCellArray, DetachAll, KillAll, SetCenter, Shift, Detach, ClearItem, MoveItem, SwapItem, unk08, unk0C, length, pad14, cells, unk20, land3DAttached, TESObjectCELL: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GridCellArray::MoveItem: SIBLING(fo4-private@1b765c70, author-permission)
// pad2D: GUESS(low)
#pragma once

#include <cstdint>

class TESObjectCELL;

class GridArray
{
public:
    virtual ~GridArray();  // 00
    virtual void DetachAll();  // 01
    virtual void KillAll();  // 02
    virtual bool SetCenter(std::int32_t a_x, std::int32_t a_y);  // 03
    virtual void Shift(std::int32_t a_x, std::int32_t a_y);  // 04
    virtual void Detach(std::uint32_t a_x, std::uint32_t a_y) = 0;  // 05
    virtual void ClearItem(std::uint32_t a_x, std::uint32_t a_y) = 0;  // 06
    virtual void MoveItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY) = 0;  // 07
    virtual void SwapItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY) = 0;  // 08

    std::uint32_t unk08;  // 08
    std::uint32_t unk0C;  // 0C
    std::uint32_t length;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(GridArray) == 0x18, "GridArray size");

class GridCellArray : public GridArray
{
public:
    ~GridCellArray() override;  // 00
    void KillAll() override;  // 02
    bool SetCenter(std::int32_t a_x, std::int32_t a_y) override;  // 03
    void Detach(std::uint32_t a_x, std::uint32_t a_y) override;  // 05
    void ClearItem(std::uint32_t a_x, std::uint32_t a_y) override;  // 06
    void MoveItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY) override;  // 07
    void SwapItem(std::uint32_t a_fromX, std::uint32_t a_fromY, std::uint32_t a_toX, std::uint32_t a_toY) override;  // 08


    TESObjectCELL** cells;  // 18
    float unk20[3];  // 20
    bool land3DAttached;  // 2C
    std::uint8_t pad2D[3];  // 2D
};
static_assert(sizeof(GridCellArray) == 0x30, "GridCellArray size");
