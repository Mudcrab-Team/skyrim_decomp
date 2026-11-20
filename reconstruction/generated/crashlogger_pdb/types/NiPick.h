// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPick; size 0x50
#pragma once

#include "CoordinateType.h"
#include "IntersectType.h"
#include "NiPoint3.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "PickType.h"
#include "Results.h"
#include "SortType.h"
struct NiPick {
    PickType pickType;
    SortType sortType;
    IntersectType intersectType;
    CoordinateType coordinateType;
    bool frontOnly;
    bool observeAppCullFlag;
    bool returnNormal;
    bool returnSmoothNormal;
    bool returnTexture;
    bool returnColor;
    unsigned short pad16;
    NiPointer_RE__NiAVObject_9e3aa701 root;
    Results pickResults;
    NiPoint3 origin;
    unsigned int pad4C;
};
static_assert(sizeof(NiPick) == 80, "NiPick layout differs from the PDB");
