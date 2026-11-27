// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPathingLocation: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// 0x11b68b0 BSPathingLocation::BSPathingLocation
#include "BSPathingLocation_11b68b0.h"

// Construct a pathing location from a position and navmesh info.
BSPathingLocation::BSPathingLocation(const NiPoint3& a_location, BSNavmeshInfo* a_navMeshInfo) :
    location(a_location),
    navMeshInfo(a_navMeshInfo),
    navMeshInfoArray(nullptr),
    pathingCell(a_navMeshInfo->pathingCell),
    triangle(0xFFFF),
    flags(1),
    clientData(0)
{}
