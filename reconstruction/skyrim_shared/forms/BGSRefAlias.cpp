// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3a2e60 BGSRefAlias::~BGSRefAlias
// Adapted bodies: none
#include "BGSRefAlias.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
BGSRefAlias::BGSRefAlias()
{
}

// The target calls the complete destructor out of line, so it stays declared only in the header.
