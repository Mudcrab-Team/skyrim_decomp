// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x315cf0 BGSAcousticSpace::Clone3D
// 0x315d50 BGSAcousticSpace::~BGSAcousticSpace
// Adapted bodies: none
#include "BGSAcousticSpace_315cf0.h"

// Emit the virtual deleting destructor with the class constructor.
BGSAcousticSpace::BGSAcousticSpace() = default;

NiAVObject* BGSAcousticSpace::Clone3D(TESObjectREFR*)
{
    return nullptr;
}

BGSAcousticSpace::~BGSAcousticSpace()
{

}
