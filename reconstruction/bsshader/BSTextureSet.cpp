// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x32dde4 BSTextureSet::~BSTextureSet
// CI hash: 0x32dde4 ??_EThunkHost@@WDA@EAAPEAXI@Z
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x32dfe0 BSTextureSet::GetRTTI
// 0x32df90 BSTextureSet::~BSTextureSet
#include "BSTextureSet.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSTextureSet::BSTextureSet()
{
}

// Compared function: RVA 0x32dfe0, 8 bytes, BSTextureSet::GetRTTI.
const NiRTTI* BSTextureSet::GetRTTI() const
{
    return &NiRTTI_BSTextureSet;
}

// Body done: RVA 0x32df90, 50 bytes, BSTextureSet::~BSTextureSet; compared as the scalar deleting
// destructor. The target does the NiRefObject cleanup itself, so keep this empty definition and the
// constructor: the inline base destructors in the header make the compiler produce the same body.
BSTextureSet::~BSTextureSet()
{
}

// Stand-ins for the second host base and the complete object whose vftable carries the thunk.
ThunkHostPrimary::~ThunkHostPrimary() {}
ThunkHost::ThunkHost() {}
ThunkHost::~ThunkHost() {}
