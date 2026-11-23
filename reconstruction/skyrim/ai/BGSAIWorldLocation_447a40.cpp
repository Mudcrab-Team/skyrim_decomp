// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x447a40 BGSAIWorldLocation::Function447a40
// Adapted bodies: none
#include "BGSAIWorldLocation_447a40.h"

// Only interior cells count; two interiors compare by cell, otherwise by worldspace.
bool BGSAIWorldLocation::Function447a40(const TESObjectREFR* a_ref) const
{
    TESObjectCELL* ours = GetCell();
    if (ours && !(ours->cellFlags & 1)) {
        ours = nullptr;
    }
    TESObjectCELL* theirs = a_ref->parentCell;
    if (theirs && !(theirs->cellFlags & 1)) {
        theirs = nullptr;
    }
    if (theirs || ours) {
        return theirs == ours;
    }
    TESWorldSpace* ourWorld = GetLocationWorldSpace();
    return a_ref->GetWorldSpace() == ourWorld;
}
