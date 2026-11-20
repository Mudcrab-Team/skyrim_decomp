// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysDragModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// LinkObject, NiPSysDragModifier::~NiPSysDragModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// linkedObject: GUESS(low)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysDragModifier : public NiPSysModifier
{
public:
    NiPSysDragModifier();
    ~NiPSysDragModifier() override = default;
    void LinkObject(NiStream& stream) override;

private:
    NiAVObject* linkedObject;
    std::uint8_t padding38[0x18];
};
static_assert(sizeof(NiPSysDragModifier) == 0x50, "measured allocation size");
