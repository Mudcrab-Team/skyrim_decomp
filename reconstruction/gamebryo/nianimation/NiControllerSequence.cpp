// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf5b4e0 NiControllerSequence::~NiControllerSequence
// Adapted bodies: none
#include "NiControllerSequence.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiControllerSequence::NiControllerSequence()
{
}

// noinline: the deleting destructor calls a separate destructor body at 0xf55450
__declspec(noinline) NiControllerSequence::~NiControllerSequence()
{
}
