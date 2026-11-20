// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfb0570 NiPSysGravityFieldModifier::SaveBinary
// 0xfb0f30 NiPSysGravityFieldModifier::dtor
// Adapted bodies: none
#include "NiPSysGravityFieldModifier.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysGravityFieldModifier::NiPSysGravityFieldModifier() = default;

void NiPSysGravityFieldModifier::SaveBinary(NiStream& stream)
{
    NiPSysFieldModifier::SaveBinary(stream);
    return axis.SaveTriple(stream);
}
