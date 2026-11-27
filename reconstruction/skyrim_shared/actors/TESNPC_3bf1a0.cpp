// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3bf1a0 TESNPC::GetShortName
// Adapted bodies: none
#include "TESNPC_3bf1a0.h"

// Returns the NPC short name when non-empty, falling back to the full name.
const char* TESNPC::GetShortName() const
{
    const char* name = shortName.GetString();
    if (!name || *name == 0) {
        return fullName.GetFullName();
    }
    return name;
}
