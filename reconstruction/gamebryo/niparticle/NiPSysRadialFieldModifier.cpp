// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfb7880 NiPSysRadialFieldModifier::IsEqual
// 0xfb8180 NiPSysRadialFieldModifier::dtor
// Adapted bodies: none
#include "NiPSysRadialFieldModifier.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysRadialFieldModifier::NiPSysRadialFieldModifier() = default;

bool NiPSysRadialFieldModifier::IsEqual(NiObject* other)
{
    return NiPSysFieldModifier::CompareFields(other) != 0;
}
