// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiKeyBasedInterpolator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiKeyBasedInterpolator::~NiKeyBasedInterpolator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "NiInterpolator.h"

class NiKeyBasedInterpolator : public NiInterpolator
{
public:
    NiKeyBasedInterpolator();
    virtual ~NiKeyBasedInterpolator();  // compared: 0xf6e9f0 (scalar deleting destructor)
};
static_assert(sizeof(NiKeyBasedInterpolator) == 0x18, "NiKeyBasedInterpolator size");
