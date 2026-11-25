// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2557d0 TESRegionList::GetDerivedData
// Adapted bodies: TESRegionList::GetDerivedData follows fo4-private@1b765c70 src/Shared/Regions/TESRegionList.cpp:226
#include "TESRegionList_2557d0.h"

TESRegionData* TESRegionList::GetDerivedData(REGION_DATA_ID aeFind, const NiPoint2& arPoint, const TESWorldSpace* apWorldSpace)
{
    TESRegionPoint point;
    point.Point.x = arPoint.x;
    point.Point.y = arPoint.y;
    return GetDerivedData(aeFind, &point, apWorldSpace);
}
