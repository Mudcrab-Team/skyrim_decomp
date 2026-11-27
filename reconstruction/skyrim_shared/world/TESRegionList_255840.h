// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionList.cpp:235
// TESRegionList, TESRegionList::GetDerivedData, REGION_DATA_ID, TESRegionPoint, TESWorldSpace: STANDIN SIBLING(fo4-private@1b765c70, author-permission); reduced to what the call needs
// TESRegionData: STANDIN SIBLING(fo4-private@1b765c70, author-permission); opaque
// NiPoint2, NiPoint3, x, y, z: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the leading members
// kNone, Point: GUESS(low)
#pragma once

#include <cstdint>

enum REGION_DATA_ID
{
    kNone = 0
};

class TESWorldSpace;
class TESRegionData;

struct NiPoint2
{
    float x;
    float y;
};

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct TESRegionPoint
{
    TESRegionPoint();

    NiPoint2 Point;
};

class TESRegionList
{
public:
    TESRegionData* GetDerivedData(REGION_DATA_ID aeFind, const NiPoint3& arPoint, const TESWorldSpace* apWorldSpace);
    TESRegionData* GetDerivedData(REGION_DATA_ID aeFind, TESRegionPoint* apPoint, const TESWorldSpace* apWorldSpace);
};
