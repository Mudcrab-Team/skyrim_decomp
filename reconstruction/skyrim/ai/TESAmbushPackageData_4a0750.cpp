// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a0750 TESAmbushPackageData::Compare
// Adapted bodies: TESAmbushPackageData::Compare from fo4-private@1b765c70 src/Shared/AI/PackageDataAmbush.cpp:40 (see the header)
#include "TESAmbushPackageData_4a0750.h"

bool TESAmbushPackageData::Compare(TESPackageData* a_other)
{
    TESAmbushPackageData* other = dynamic_cast<TESAmbushPackageData*>(a_other);
    if (!other)
        return true;
    if (pAmbushLocation)
    {
        if (pAmbushLocation->Compare(other->pAmbushLocation))
            return true;
    }
    else if (other->pAmbushLocation)
    {
        return true;
    }
    return false;
}
