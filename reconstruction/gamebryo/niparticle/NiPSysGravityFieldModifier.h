// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysGravityFieldModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// SaveBinary, NiPSysGravityFieldModifier::~NiPSysGravityFieldModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// axis: GUESS(low)
#pragma once

#include <cstdint>

#include "NiPSysFieldModifier.h"

class NiPSysGravityFieldModifier : public NiPSysFieldModifier
{
public:
    NiPSysGravityFieldModifier();
    ~NiPSysGravityFieldModifier() override = default;
    void SaveBinary(NiStream& stream) override;

private:
    NiPoint3 axis;
    std::uint8_t padding5C[0xC];
};
static_assert(sizeof(NiPSysGravityFieldModifier) == 0x68, "measured allocation size");
