// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1003990 BSPSysScaleModifier::SaveBinary
// Adapted bodies: none
#include "BSPSysScaleModifier.h"

void BSPSysScaleModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    return scaleData->SaveBinary(stream);
}
