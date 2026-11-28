// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0x4bdd00 NavMesh::IsValidVertexLocation
#include "NavMesh_4bdd00.h"

#include <cmath>

// Return whether all three coordinates are finite and within the maximum coordinate bound.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool NavMesh::IsValidVertexLocation(const NiPoint34bdd00& a_loc)
{
    return _finite(a_loc.x) && std::fabs(a_loc.x) <= gMaxVertexCoord &&
           _finite(a_loc.y) && std::fabs(a_loc.y) <= gMaxVertexCoord &&
           _finite(a_loc.z) && std::fabs(a_loc.z) <= gMaxVertexCoord;
}
