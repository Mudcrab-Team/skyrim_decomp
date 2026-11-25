// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x11deea0 (skyrim_shared/pathfinding/BSNavmesh): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmeshTriangleDoorPortal, BSNavmeshGrid: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NavmeshCursor, NavmeshEdgeOut, BSNavmeshGridCell, BSNavmeshDoorPortalArray: GUESS(low)
// Functionb65800, Ownerb65800: GUESS(low) STANDIN
// unknown08, unknown70, unknownD0, ForwardMeshGrid, Function11dfcc0, Function11e0100, Function11e01e0, Function11e02a0, Function11e02c0, Function11e70c0: GUESS(low) STANDIN
#pragma once
#include "BSNavmesh.h"

class Ownerb65800
{
public:
    Ownerb65800();
    virtual ~Ownerb65800();

    void ForwardMeshGrid();
    void* Functionb65800() const;
    static void Function11dfcc0(const NavmeshCursor* a_cursor, NavmeshEdgeOut* a_out);
    static void Function11e0100(const NavmeshCursor* a_cursor, NavmeshEdgeOut* a_out);
    BSNavmeshTriangleDoorPortal* Function11e01e0(std::uint16_t a_index) const;
    BSNavmeshTriangleDoorPortal* Function11e02a0(std::uint16_t a_index) const;
    std::int32_t Function11e02c0(std::uint16_t a_triangleIndex) const;
    std::uint32_t GetGridCellCount() const;
    BSNavmeshGridCell* Function11e70c0(std::uint32_t a_cellIndex) const;

    std::uint8_t unknown08[0x50];  // 08
    BSNavmeshDoorPortalArray doorPortals;  // 58
    std::uint8_t unknown70[0x30];  // 70
    BSNavmeshGrid meshGrid;  // A0
    std::uint8_t unknownD0[0x40];  // D0
    void* unk110;  // 110
};
static_assert(sizeof(Ownerb65800) == 0x118, "Ownerb65800 size");
