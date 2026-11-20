// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysRadialFieldModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// IsEqual, NiPSysRadialFieldModifier::~NiPSysRadialFieldModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

#include "NiPSysFieldModifier.h"

class NiPSysRadialFieldModifier : public NiPSysFieldModifier
{
public:
    NiPSysRadialFieldModifier();
    ~NiPSysRadialFieldModifier() override = default;
    bool IsEqual(NiObject* other) override;

private:
    std::uint8_t padding50[0x8];
};
static_assert(sizeof(NiPSysRadialFieldModifier) == 0x58, "measured allocation size");
