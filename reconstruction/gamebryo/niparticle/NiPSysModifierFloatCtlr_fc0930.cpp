// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the observed cleanup calls.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfc0930 NiPSysModifierFloatCtlr::LoadBinary
// 0xfc0d70 NiPSysModifierFloatCtlr::dtor
// Adapted bodies: none
#include "NiPSysModifierFloatCtlr_fc0930.h"
#include "NiPSysModifier.h"

// Emit the deleting destructor through the class constructor.
NiPSysModifierFloatCtlr::NiPSysModifierFloatCtlr() = default;

void NiPSysModifierFloatCtlr::LoadBinary(NiStream& stream)
{
    NiPSysModifierCtlr::LoadBinary(stream);
    if (stream.nifMaxVersion < 0x0A010068) {
        return stream.LoadLinkID();
    }
}
