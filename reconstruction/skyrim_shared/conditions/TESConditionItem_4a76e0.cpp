// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a76e0 TESConditionItem::Compare
// Adapted bodies: TESConditionItem::Compare from fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:101 (see the header)
#include "TESConditionItem_4a76e0.h"

bool TESConditionItem::Compare(const TESConditionItem* a_other) const
{
    if (!a_other)
        return true;
    if (Data.iFlags != a_other->Data.iFlags)
        return true;
    if (Data.pGlobal != a_other->Data.pGlobal)
        return true;
    if (Data.eObject != a_other->Data.eObject)
        return true;
    if (Data.hRunOnRef.iBits != a_other->Data.hRunOnRef.iBits)
        return true;
    if (Data.uiDataID != a_other->Data.uiDataID)
        return true;
    bool result = TESParameters::Compare(a_other->Data.FunctionData, Data.FunctionData);
    if (result)
        return true;
    return false;
}
