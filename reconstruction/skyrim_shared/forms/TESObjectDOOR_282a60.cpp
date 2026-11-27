// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x282a60 TESObjectDOOR::ClearData
// Adapted bodies: TESObjectDOOR::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesobjectdoor.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:26311 (AutoMemContext destructor similarity, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (AutoMemContext constructor similarity, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesobjectdoor.cpp:259
#include "TESObjectDOOR_282a60.h"

AutoMemContext::~AutoMemContext()
{
    g_allocationContext = saved;
}

inline void TESObjectDOOR::ClearRandomTeleportList()
{
    AutoMemContext context(101);
    AutoMemContext arrayContext(101);
    randomTeleports.Clear();
}

void TESObjectDOOR::ClearData()
{
    ClearRandomTeleportList();
}
