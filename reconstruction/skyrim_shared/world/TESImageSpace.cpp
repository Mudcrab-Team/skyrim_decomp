// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations; the destructor body equals the FNV sibling's one-line body
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesimagespace.cpp:68
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a67e0 TESImageSpace::~TESImageSpace
// Adapted bodies: TESImageSpace::~TESImageSpace
#include "TESImageSpace.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
TESImageSpace::TESImageSpace()
{
}

// The target clears the form data, then calls the base destructor.
TESImageSpace::~TESImageSpace()
{
    ClearData();
}
