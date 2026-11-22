// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; pinned image).
// Adapted bodies: none.
// 0x11e99f0 BSNavmesh::~BSNavmesh
// 0x11e7580 BSNavmesh::ForwardMeshGrid
// 0x11deea0 BSNavmesh::Function11deea0
// 0x11dfcc0 BSNavmesh::Function11dfcc0
// 0x11e0100 BSNavmesh::Function11e0100
// 0x11e01e0 BSNavmesh::Function11e01e0
// 0x11e02a0 BSNavmesh::Function11e02a0
// 0x11e02c0 BSNavmesh::Function11e02c0
// 0x11e70b0 BSNavmesh::Function11e70b0
// 0x11e70c0 BSNavmesh::Function11e70c0
// ForwardMeshGrid, NavmeshEdgeHelper2, NavmeshEdgeHelper3: GUESS(low)
#include "BSNavmesh.h"

void NavmeshEdgeHelper2(void* a_mesh, std::uint16_t a_triangleIndex, std::uint32_t a_edgeIndex, std::uint64_t* a_first, std::uint64_t* a_second);
void NavmeshEdgeHelper3(void* a_mesh, std::uint16_t a_triangleIndex, std::uint32_t a_edgeIndex, std::uint64_t* a_first, std::uint64_t* a_second, std::uint64_t* a_third);

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSNavmesh::BSNavmesh()
{
}

void BSNavmesh::ForwardMeshGrid()
{
    meshGrid.Unk11dd370();
}

void* BSNavmesh::Function11deea0() const
{
    return unk110;
}

void BSNavmesh::Function11dfcc0(const NavmeshCursor* a_cursor, NavmeshEdgeOut* a_out)
{
    NavmeshEdgeHelper2(a_cursor->mesh, a_cursor->triangleIndex, a_cursor->edgeIndex, &a_out->first, &a_out->second);
}

void BSNavmesh::Function11e0100(const NavmeshCursor* a_cursor, NavmeshEdgeOut* a_out)
{
    NavmeshEdgeHelper3(a_cursor->mesh, a_cursor->triangleIndex, a_cursor->edgeIndex, &a_out->first, &a_out->second, &a_out->third);
}

BSNavmeshTriangleDoorPortal* BSNavmesh::Function11e01e0(std::uint16_t a_index) const
{
    return &doorPortals.data[a_index];
}

BSNavmeshTriangleDoorPortal* BSNavmesh::Function11e02a0(std::uint16_t a_index) const
{
    return &doorPortals.data[a_index];
}

std::int32_t BSNavmesh::Function11e02c0(std::uint16_t a_triangleIndex) const
{
    std::int32_t count = static_cast<std::int32_t>(doorPortals.size);
    for (std::int32_t i = 0; i < count; ++i) {
        if (doorPortals.data[static_cast<std::uint32_t>(i)].owningTriangleIndex == a_triangleIndex) {
            return i;
        }
    }
    return -1;
}

std::uint32_t BSNavmesh::Function11e70b0() const
{
    return meshGrid.gridSize * meshGrid.gridSize;
}

BSNavmeshGridCell* BSNavmesh::Function11e70c0(std::uint32_t a_cellIndex) const
{
    if (a_cellIndex >= meshGrid.gridSize * meshGrid.gridSize) {
        return nullptr;
    }
    return &meshGrid.gridData[a_cellIndex];
}
