// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1474f0 BGSDualCastData::~BGSDualCastData
// Adapted bodies: none
#include "BGSDualCastData.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
BGSDualCastData::BGSDualCastData()
{
}

BGSDualCastData::~BGSDualCastData()
{
    ClearData();
}
