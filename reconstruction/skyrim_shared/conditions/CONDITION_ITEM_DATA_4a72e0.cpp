// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a72e0 CONDITION_ITEM_DATA::Copy
// Adapted bodies: CONDITION_ITEM_DATA::Copy from fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:161 (see the header)
#include "CONDITION_ITEM_DATA_4a72e0.h"

void CONDITION_ITEM_DATA::Copy(const CONDITION_ITEM_DATA& a_copyFrom)
{
    pGlobal = a_copyFrom.pGlobal;
    hRunOnRef.iBits = a_copyFrom.hRunOnRef.iBits;
    uiDataID = a_copyFrom.uiDataID;
    TESParameters::Copy(a_copyFrom.FunctionData, FunctionData);
    iFlags = a_copyFrom.iFlags;
    eObject = a_copyFrom.eObject;
}
