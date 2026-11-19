// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3fb6b0 BSWin32TaskletData::~BSWin32TaskletData
// Adapted bodies: none
#include "BSWin32TaskletData.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
BSWin32TaskletData::BSWin32TaskletData()
{
}

// The compared function is the deleting destructor that the compiler emits beside the
// vftable. The plain destructor stays declared only: the target's deleting form calls it,
// and a definition here would inline its vftable store into the compared body.
