// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysDragFieldModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// NiPSysDragFieldModifier::~NiPSysDragFieldModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class NiPSysDragFieldModifier : public NiPSysModifier
{
public:
    NiPSysDragFieldModifier();
    ~NiPSysDragFieldModifier() override = default;

private:
    std::uint8_t padding30[0x30];
};
static_assert(sizeof(NiPSysDragFieldModifier) == 0x60, "measured allocation size");
