// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xf9c220 NiPSysGravityModifier::CopyMembers
#include "NiPSysGravityModifier_f9c220.h"

// Copies base modifier state and gravity parameters into dest.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void NiPSysGravityModifier::CopyMembers(NiPSysGravityModifier* dest, NiCloningProcess& process)
{
    NiPSysModifier::CopyMembers(dest, process);
    dest->gravityAxis.x = gravityAxis.x;
    dest->gravityAxis.y = gravityAxis.y;
    dest->gravityAxis.z = gravityAxis.z;
    dest->decay = decay;
    dest->strength = strength;
    dest->forceType = forceType;
    dest->turbulence = turbulence;
    dest->turbulenceScale = turbulenceScale;
    dest->worldAligned = worldAligned;
}
