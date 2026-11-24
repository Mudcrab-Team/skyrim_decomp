// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: TESAmbushPackageData::Compare_0067af50.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/packagedataambush.cpp:107
// 0x4a0750 TESAmbushPackageData::Compare_0067af50
#include "TESAmbushPackageData_4a0750.h"

bool TESAmbushPackageData::Compare_0067af50(TESPackageData* apCompare)
{
    TESAmbushPackageData* pkOther = dynamic_cast<TESAmbushPackageData*>(apCompare);
    if (!pkOther)
        return true;

    if (pAmbushLocation)
    {
        if (pAmbushLocation->PackageLocation_Compare(pkOther->pAmbushLocation))
            return true;
    }
    else if (pkOther->pAmbushLocation)
    {
        return true;
    }
    return false;
}
