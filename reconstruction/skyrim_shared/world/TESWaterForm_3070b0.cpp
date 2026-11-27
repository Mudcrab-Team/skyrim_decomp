// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3070b0 TESWaterForm::Function3070b0
#include "TESWaterForm_3070b0.h"

void* TESWaterForm::Function3070b0(std::uint32_t a_index)
{
    switch (a_index)
    {
    case 0:
        return entry80.Function_eb1380();
    case 1:
        return entry90.Function_eb1380();
    case 2:
        return entryA0.Function_eb1380();
    case 3:
        return entryB0.Function_eb1380();
    default:
        return nullptr;
    }
}
