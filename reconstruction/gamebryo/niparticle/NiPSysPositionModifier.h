// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysPositionModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// NiPSysPositionModifier::~NiPSysPositionModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysPositionModifier : public NiPSysModifier
{
public:
    NiPSysPositionModifier();
    ~NiPSysPositionModifier() override = default;
};
static_assert(sizeof(NiPSysPositionModifier) == 0x30, "measured allocation size");
