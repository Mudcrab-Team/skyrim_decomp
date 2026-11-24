// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2b8200 TESObjectCELL::ClearData
// Adapted bodies: TESObjectCELL::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesobjectcell.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:26311 (AutoMemContext destructor similarity, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (AutoMemContext constructor similarity, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesobjectcell.cpp:242
#include "TESObjectCELL_2b8200.h"

#include <new>

AutoMemContext::~AutoMemContext()
{
    g_allocationContext = saved;
}

void TESObjectCELL::ClearData()
{
    AutoMemContext context(106);
    extraList.RemoveNonPersistentCellData();

    if (cellFlags & 1)
        ::operator delete(cellData.interior, sizeof(INTERIOR_DATA));
    else if (auto* exterior = cellData.exterior)
        exterior->Destroy(1);

    cellData.interior = nullptr;
    unk138 = 0;
}
