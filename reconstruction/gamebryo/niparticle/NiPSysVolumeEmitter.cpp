// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfc0310 NiPSysVolumeEmitter::LoadBinary
// 0xfc0340 NiPSysVolumeEmitter::LinkObject
// 0xfc0390 NiPSysVolumeEmitter::SaveBinary
// 0xfc08d0 NiPSysVolumeEmitter::dtor
// Adapted bodies: none
#include "NiPSysVolumeEmitter.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysVolumeEmitter::NiPSysVolumeEmitter() = default;

void NiPSysVolumeEmitter::LoadBinary(NiStream& stream)
{
    LoadBase(stream);
    return stream.LoadLinkID();
}

void NiPSysVolumeEmitter::LinkObject(NiStream& stream)
{
    LinkBase(stream);
    linkedObject = stream.ReadLinkID();
}

void NiPSysVolumeEmitter::SaveBinary(NiStream& stream)
{
    SaveBase(stream);
    return stream.SaveLinkID(reinterpret_cast<const NiObject*>(linkedObject));
}
