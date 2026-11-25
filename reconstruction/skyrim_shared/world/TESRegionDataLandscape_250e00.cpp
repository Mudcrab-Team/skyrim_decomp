// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x250e00 TESRegionDataLandscape::~TESRegionDataLandscape
// Adapted bodies: TESRegionDataLandscape::~TESRegionDataLandscape follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatalandscape.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatalandscape.cpp:213
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/region system/tesregiondatalandscape.cpp:75
#include "TESRegionDataLandscape_250e00.h"

// The constructor emits this class's vftable and deleting destructor.
TESRegionDataLandscape::TESRegionDataLandscape() = default;

TESRegionDataLandscape::~TESRegionDataLandscape()
{
    if (icon) {
        delete icon;
    }
}
