// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x2bec10 TESObjectCELL::GetLandHeight
// Adapted bodies: TESObjectCELL::GetLandHeight follows fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectCELL.cpp:2764
#include "TESObjectCELL_2bec10.h"

bool TESObjectCELL::GetLandHeight(const NiPoint3& arPos, float& arHeight)
{
    TESObjectLAND* pLand = GetLand();
    if (pLand)
        return pLand->GetLandHeight(arPos, arHeight);
    arHeight = 0.0f;
    return false;
}
