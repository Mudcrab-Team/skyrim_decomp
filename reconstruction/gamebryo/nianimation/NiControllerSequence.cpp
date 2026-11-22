// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original stand-in; the pinned image listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf5b4e0 NiControllerSequence::~NiControllerSequence
// Adapted bodies: none
#include "NiControllerSequence.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiControllerSequence::NiControllerSequence()
{
}

// ~NiControllerSequence stays declared but undefined: the compared deleting destructor
// calls the complete destructor out of line (cookbook rule 18).
