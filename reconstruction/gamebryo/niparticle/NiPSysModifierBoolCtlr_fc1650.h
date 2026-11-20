// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the observed cleanup calls.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysModifierBoolCtlr: EXE_RTTI
// NiPSysModifierCtlr: STANDIN EXE_RTTI
// LoadBinary: OBSERVED
// LoadBinary occupies the NiObject stream slot.
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "NiPSysModifierCtlr_fa0ab0.h"

class NiPSysModifierBoolCtlr : public NiPSysModifierCtlr
{
public:
    NiPSysModifierBoolCtlr();
    ~NiPSysModifierBoolCtlr() override = default;
    void LoadBinary(NiStream& stream);
};
static_assert(sizeof(NiPSysModifierBoolCtlr) == 0x60, "observed allocation size");
