// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xfbfb20 BSPSysInheritVelocityModifier::CopyMembers
#include "BSPSysInheritVelocityModifier_fbfb20.h"

// Copies the base modifier fields and the three trailing scalar velocity parameters.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void BSPSysInheritVelocityModifier::CopyMembers(BSPSysInheritVelocityModifier* destination)
{
    NiPSysModifier::Functionfa0f00(destination);
    destination->unk54 = unk54;
    destination->unk58 = unk58;
    destination->unk5C = unk5C;
}
