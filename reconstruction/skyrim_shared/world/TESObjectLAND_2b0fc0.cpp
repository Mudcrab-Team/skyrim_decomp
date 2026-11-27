// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2b0fc0 TESObjectLAND::GetGeometry
// Adapted bodies: none
#include "TESObjectLAND_2b0fc0.h"

// Returns the first child geometry object of the given land quadrant mesh, or null if absent.
NiAVObject* TESObjectLAND::GetGeometry(std::uint32_t a_quad) const
{
    if (!loadedData) {
        return nullptr;
    }
    NiNode* quadNode = loadedData->mesh[a_quad];
    if (quadNode && quadNode->childrenSize > 0) {
        return quadNode->childrenData[0];
    }
    return nullptr;
}
