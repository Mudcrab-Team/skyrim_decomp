// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1869c0 ExtraGuardedRefData::Load
// Adapted bodies: none
#include "ExtraGuardedRefData_1869c0.h"

void ExtraGuardedRefData::Load(BGSLoadGameBuffer* buffer)
{
    buffer->ReadFormID(&refId);
    buffer->LoadDataEndian(&value, 4, 4);
    buffer->LoadDataEndian(&flag, 1, 1);
}
