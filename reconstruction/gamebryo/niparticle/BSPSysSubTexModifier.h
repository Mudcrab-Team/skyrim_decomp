// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysSubTexModifier: GUESS(low)
// Class spelling follows the qualified Address Library names.
// BSPSysSubTexModifier::~BSPSysSubTexModifier: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

#include "NiPSysModifier.h"

class BSPSysSubTexModifier : public NiPSysModifier
{
public:
    BSPSysSubTexModifier();
    ~BSPSysSubTexModifier() override = default;

private:
    std::uint8_t padding30[0x20];
};
static_assert(sizeof(BSPSysSubTexModifier) == 0x50, "measured allocation size");
