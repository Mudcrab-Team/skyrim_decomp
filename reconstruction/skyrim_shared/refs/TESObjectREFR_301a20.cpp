// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x301a20 TESObjectREFR::Function301a20
// Adapted bodies: none
#include "TESObjectREFR_301a20.h"

BSExtraData* TESObjectREFR::Function301a20() const
{
    BSExtraData* data = nullptr;
    if (gMarkerBases.IsMarkerBase(GetBaseObject())) {
        data = extraList.GetMultiBoundMarkerData();
    }
    return data;
}
