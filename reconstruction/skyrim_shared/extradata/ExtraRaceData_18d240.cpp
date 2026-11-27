// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x18d240 ExtraRaceData::~ExtraRaceData
// CI hash: 0x18d240 ??1ExtraRaceData@@UEAA@XZ
// Adapted bodies: none
#include "ExtraRaceData_18d240.h"

// Releases the reference-counted race data pointer during ExtraRaceData teardown.
ExtraRaceData::~ExtraRaceData()
{
    RaceDataRef* ptr = raceData;
    // intrusive ref-count: atomic release of race data
    if (ptr && _InterlockedDecrement(&ptr->refCount) == 0) {
        delete ptr;
    }
}
