// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x29e6b0 BGSLocationRefType::~BGSLocationRefType
// Adapted bodies: none
#include "BGSLocationRefType.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
BGSLocationRefType::BGSLocationRefType()
{
}

// Stores its own vftable, clears the TESForm data, then runs the BGSKeyword destructor.
BGSLocationRefType::~BGSLocationRefType()
{
    TESForm::ClearData();
}
