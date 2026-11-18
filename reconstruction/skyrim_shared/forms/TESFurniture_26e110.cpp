// Code origin: InitializeData and Clone3D bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x26e110 TESFurniture::InitializeData
// 0x26ed80 TESFurniture::Clone3D
#include "TESFurniture_26e110.h"
void TESFurniture::InitializeData()
{
    furnFlags = 0;
    associatedForm = nullptr;
    TESObjectACTI::InitializeData();
}
NiAVObject* TESFurniture::Clone3D(TESObjectREFR* a_ref)
{
    NiAVObject* node = TESBoundObject::Clone3D(a_ref);
    if (g_furnitureCloneFlag) {
        Unk26f900(node);
    }
    return node;
}
