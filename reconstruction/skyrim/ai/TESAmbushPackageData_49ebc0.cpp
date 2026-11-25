// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x49ebc0 TESAmbushPackageData::`scalar deleting destructor'
// Adapted bodies: none
#include "TESAmbushPackageData_49ebc0.h"

// Defined here so the deleting destructor is emitted beside the vftable.
TESAmbushPackageData::~TESAmbushPackageData()
{
    delete payload;
}
