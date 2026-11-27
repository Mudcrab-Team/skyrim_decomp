// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x4a1640 TESUseItemPackageData::`scalar deleting destructor'
// Adapted bodies: none
#include "TESUseItemPackageData_4a1640.h"

// Defined here so the deleting destructor is emitted beside the vftable.
TESUseItemPackageData::~TESUseItemPackageData()
{
    delete payload;
}
