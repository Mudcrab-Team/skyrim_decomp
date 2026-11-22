// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh, BSNavmesh::~BSNavmesh, BSNavmesh::doorPortals, BSNavmesh::meshGrid, BSNavmesh::unk110: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSNavmeshTriangleDoorPortal, owningTriangleIndex, BSNavmeshGrid, gridSize, gridData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NavmeshCursor, NavmeshEdgeOut, BSNavmeshGridCell, BSNavmeshDoorPortalArray, unknown08, unknown70, unknownD0, ForwardMeshGrid, Function11deea0, Function11dfcc0, Function11e0100, Function11e01e0, Function11e02a0, Function11e02c0, Function11e70b0, Function11e70c0: GUESS(low)
#pragma once

#include <cstdint>

struct BSNavmeshTriangleDoorPortal
{
    void* door;  // 00
    std::uint16_t owningTriangleIndex;  // 08
    std::uint16_t pad0A;  // 0A
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(BSNavmeshTriangleDoorPortal) == 0x10, "BSNavmeshTriangleDoorPortal size");

struct BSNavmeshDoorPortalArray
{
    BSNavmeshTriangleDoorPortal* data;  // 00
    std::uint32_t capacity;  // 08
    std::uint32_t pad0C;  // 0C
    std::uint32_t size;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(BSNavmeshDoorPortalArray) == 0x18, "BSNavmeshDoorPortalArray size");

struct BSNavmeshGridCell
{
    std::uint8_t unknown00[0x18];  // 00
};
static_assert(sizeof(BSNavmeshGridCell) == 0x18, "BSNavmeshGridCell size");

// BSNavmeshGrid: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to its 0x30-byte size
// BSNavmeshGrid::Unk11dd370: GUESS(low); the callee at RVA 0x11dd370, declared, not defined here
class BSNavmeshGrid
{
public:
    void Unk11dd370();

    std::uint32_t gridSize;  // 00
    std::uint8_t unknown04[0x24];  // 04
    BSNavmeshGridCell* gridData;  // 28
};
static_assert(sizeof(BSNavmeshGrid) == 0x30, "BSNavmeshGrid size");

struct NavmeshCursor
{
    void* mesh;  // 00
    std::uint16_t triangleIndex;  // 08
    std::uint16_t pad0A;  // 0A
    std::uint32_t pad0C;  // 0C
    std::uint32_t edgeIndex;  // 10
};

struct NavmeshEdgeOut
{
    std::uint64_t first;  // 00
    std::uint64_t second;  // 08
    std::uint64_t third;  // 10
};

class BSNavmesh
{
public:
    BSNavmesh();
    virtual ~BSNavmesh();  // compared: 0x11e99f0 (scalar deleting destructor)

    void ForwardMeshGrid();
    void* Function11deea0() const;
    static void Function11dfcc0(const NavmeshCursor* a_cursor, NavmeshEdgeOut* a_out);
    static void Function11e0100(const NavmeshCursor* a_cursor, NavmeshEdgeOut* a_out);
    BSNavmeshTriangleDoorPortal* Function11e01e0(std::uint16_t a_index) const;
    BSNavmeshTriangleDoorPortal* Function11e02a0(std::uint16_t a_index) const;
    std::int32_t Function11e02c0(std::uint16_t a_triangleIndex) const;
    std::uint32_t Function11e70b0() const;
    BSNavmeshGridCell* Function11e70c0(std::uint32_t a_cellIndex) const;

    std::uint8_t unknown08[0x50];  // 08
    BSNavmeshDoorPortalArray doorPortals;  // 58
    std::uint8_t unknown70[0x30];  // 70
    BSNavmeshGrid meshGrid;  // A0
    std::uint8_t unknownD0[0x40];  // D0
    void* unk110;  // 110
};
static_assert(sizeof(BSNavmesh) == 0x118, "BSNavmesh size");
