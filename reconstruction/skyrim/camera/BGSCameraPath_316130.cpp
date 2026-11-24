// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x316130 BGSCameraPath::ClearData
// Adapted bodies: BGSCameraPath::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgscamerapath.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (TestBit similarity).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgscamerapath.cpp:32
#include "BGSCameraPath_316130.h"

namespace
{
bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1) != 0;
}
}

void BGSCameraPath::ClearData()
{
    if (g_updateCameraPathLinks && TestBit(formFlags, 3) && prevPath)
        prevPath->RemoveChildPath(this);

    conditions.Clear();
    shots.RemoveAll();
}
