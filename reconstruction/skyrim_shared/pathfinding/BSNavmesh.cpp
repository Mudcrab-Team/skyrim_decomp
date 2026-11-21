// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x11e99f0 BSNavmesh::~BSNavmesh
// 0x11e7580 BSNavmesh::ForwardMeshGrid
// ForwardMeshGrid: GUESS(low)
#include "BSNavmesh.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSNavmesh::BSNavmesh()
{
}



void BSNavmesh::ForwardMeshGrid()
{
    meshGrid.Unk11dd370();
}
