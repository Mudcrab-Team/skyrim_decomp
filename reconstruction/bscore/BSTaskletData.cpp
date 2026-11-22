// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the pinned image listing and community declarations only
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xec3d20 BSTaskletData::OnStartup
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
#include "BSTaskletData.h"

bool BSTaskletData::OnStartup()
{
    return true;
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSTaskletData::BSTaskletData()
{
}
