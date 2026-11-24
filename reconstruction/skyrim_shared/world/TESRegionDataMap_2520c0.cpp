// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2520c0 TESRegionDataMap::~TESRegionDataMap
// Adapted bodies: TESRegionDataMap::~TESRegionDataMap follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatamap.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatamap.cpp:95
#include "TESRegionDataMap_2520c0.h"

// The constructor emits this class's vftable and deleting destructor.
TESRegionDataMap::TESRegionDataMap() = default;

TESRegionDataMap::~TESRegionDataMap() = default;
