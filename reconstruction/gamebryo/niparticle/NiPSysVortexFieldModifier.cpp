// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfbc050 NiPSysVortexFieldModifier::LoadBinary
// 0xfbc0b0 NiPSysVortexFieldModifier::SaveBinary
// 0xfbcfc0 NiPSysVortexFieldModifier::dtor
// Adapted bodies: none
#include "NiPSysVortexFieldModifier.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysVortexFieldModifier::NiPSysVortexFieldModifier() = default;

void NiPSysVortexFieldModifier::LoadBinary(NiStream& stream)
{
    NiPSysFieldModifier::LoadBinary(stream);
    return axis.LoadTriple(stream);
}

void NiPSysVortexFieldModifier::SaveBinary(NiStream& stream)
{
    NiPSysFieldModifier::SaveBinary(stream);
    return axis.SaveTriple(stream);
}
