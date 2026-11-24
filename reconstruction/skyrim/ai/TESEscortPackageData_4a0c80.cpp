// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// 0x4a0c80 TESEscortPackageData::~TESEscortPackageData
// Adapted bodies: TESEscortPackageData::~TESEscortPackageData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/packagedataescort.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/packagedataescort.cpp:93
#include "TESEscortPackageData_4a0c80.h"

// The constructor emits this class's vftable and deleting destructor.
TESEscortPackageData::TESEscortPackageData() = default;

TESEscortPackageData::~TESEscortPackageData()
{
    delete pSearchLocation;
}
