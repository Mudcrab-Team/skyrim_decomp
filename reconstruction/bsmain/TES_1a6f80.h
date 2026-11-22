// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout for query dispatch through the loaded grid.
// TES, GridCellArray, gridCells, interiorCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetCellSlot, ResolveCellQueryNode, ResolveQueryNode, QueryWorldNode: GUESS(low)
#pragma once

#include <cstdint>

class NiAVObject;
class TESObjectCELL;
struct CellSurfaceQuery;

class GridCellArray
{
public:
    TESObjectCELL** GetCellSlot(std::uint32_t x, std::uint32_t y) const;
};

class TES
{
public:
    NiAVObject* ResolveCellQueryNode(const CellSurfaceQuery& query);
    NiAVObject* ResolveQueryNode(const CellSurfaceQuery& query, bool useCell);
    NiAVObject* QueryWorldNode(const CellSurfaceQuery& query);

private:
    std::uint8_t unknown00[0x78];
    GridCellArray* gridCells;
    std::uint8_t unknown80[0x40];
    TESObjectCELL* interiorCell;
};
