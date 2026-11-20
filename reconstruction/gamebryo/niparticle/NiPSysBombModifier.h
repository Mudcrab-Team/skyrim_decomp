// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysBombModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// LinkObject, NiPSysBombModifier::~NiPSysBombModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// linkedObject: GUESS(low)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysBombModifier : public NiPSysModifier
{
public:
    NiPSysBombModifier();
    ~NiPSysBombModifier() override = default;
    void LinkObject(NiStream& stream) override;

private:
    NiAVObject* linkedObject;
    std::uint8_t padding38[0x20];
};
static_assert(sizeof(NiPSysBombModifier) == 0x58, "measured allocation size");
