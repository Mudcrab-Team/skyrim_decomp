// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSOcclusionPlane, GetCorners: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfe88c0 BSOcclusionPlane::GetCorners
#include "BSOcclusionPlane_fe88c0.h"

#include <cstring>

void BSOcclusionPlane::GetCorners(NiPoint3* destination)
{
    UpdateCorners();
    memcpy_s(destination, sizeof(corners), corners, sizeof(corners));
}
