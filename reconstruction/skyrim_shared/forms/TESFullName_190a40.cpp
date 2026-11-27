// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x190a40 MapMarkerData::Compare
// Adapted bodies: MapMarkerData::Compare from fo4-private@1b765c70 src/Shared/ExtraData/MapMarkerData.cpp:210 (see the header)
#include "TESFullName_190a40.h"

bool MapMarkerData::Compare(const MapMarkerData* a_rhs) const
{
    if (locationName.CompareComponent(&a_rhs->locationName))
        return true;
    if (flags != a_rhs->flags)
        return true;
    if (type != a_rhs->type)
        return true;
    return false;
}
