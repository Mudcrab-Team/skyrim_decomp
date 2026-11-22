// Source exposure: mixed (pinned image listing, labelled declarations and sibling source).
// Code origin: original reconstruction and the cited sibling adaptation.
// Adapted bodies: GetType from the cited Fallout 4 sibling (author-permission).
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyOrbit.cpp:67
// 0x4f74f0 PathingRequestFlyOrbit::GetType
// SPDX-License-Identifier: CC0-1.0
// 0x4f7680 PathingRequestFlyOrbit::SetOrbitPoint
// 0x4f76b0 PathingRequestFlyOrbit::GetOrbitPoint
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// NiPoint3 layout: CRASHLOGGER_PDB(59818@2026.10.24)
// SetOrbitPoint, GetOrbitPoint, orbitPoint: GUESS(low)
// PathingRequestFlyOrbit::GetType: SIBLING(fo4-private@1b765c70, author-permission)
#include "PathingRequestFlyOrbit.h"

extern unsigned int PathingRequestFlyOrbit_typeCRC;
extern const char PathingRequestFlyOrbit_typeName[];
void GenerateTypeCRC(unsigned int&, const char*, unsigned int);

unsigned int PathingRequestFlyOrbit::GetType() const { if (!PathingRequestFlyOrbit_typeCRC) GenerateTypeCRC(PathingRequestFlyOrbit_typeCRC, PathingRequestFlyOrbit_typeName, 0); return PathingRequestFlyOrbit_typeCRC; }

// Store the three coordinates used by the orbit request.
void PathingRequestFlyOrbit::SetOrbitPoint(const NiPoint3& a_point)
{
    orbitPoint.x = a_point.x;
    orbitPoint.y = a_point.y;
    orbitPoint.z = a_point.z;
}

// Write the orbit point into the caller's result.
NiPoint3& PathingRequestFlyOrbit::GetOrbitPoint(NiPoint3& a_out) const
{
    a_out.x = orbitPoint.x;
    a_out.y = orbitPoint.y;
    a_out.z = orbitPoint.z;
    return a_out;
}
