// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// NiPSysEmitterCtlr: EXE_RTTI
// GetInterpolator: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

class NiInterpolator;

class NiPSysEmitterCtlr
{
public:
    NiInterpolator* GetInterpolator(std::uint16_t a_index) const;
};
