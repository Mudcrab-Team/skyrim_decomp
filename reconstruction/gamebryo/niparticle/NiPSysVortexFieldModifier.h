// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysVortexFieldModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// LoadBinary, SaveBinary, NiPSysVortexFieldModifier::~NiPSysVortexFieldModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// axis: GUESS(low)
#pragma once

#include <cstdint>

#include "NiPSysFieldModifier.h"

class NiPSysVortexFieldModifier : public NiPSysFieldModifier
{
public:
    NiPSysVortexFieldModifier();
    ~NiPSysVortexFieldModifier() override = default;
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;

private:
    NiPoint3 axis;
};
static_assert(sizeof(NiPSysVortexFieldModifier) == 0x60, "measured allocation size");
