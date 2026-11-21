// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the observed cleanup calls.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfc1650 NiPSysModifierBoolCtlr::LoadBinary
// 0xfc1a90 NiPSysModifierBoolCtlr::dtor
// Adapted bodies: none
#include "NiPSysModifierBoolCtlr_fc1650.h"
#include "NiPSysModifier.h"

// Emit the deleting destructor through the class constructor.
NiPSysModifierBoolCtlr::NiPSysModifierBoolCtlr() = default;

void NiPSysModifierBoolCtlr::LoadBinary(NiStream& stream)
{
    NiPSysModifierCtlr::LoadBinary(stream);
    if (stream.nifMaxVersion < 0x0A010068) {
        return stream.LoadLinkID();
    }
}
