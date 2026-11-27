// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation based on the pinned game build, with the cited declarations.
// Adapted bodies: none
// 0xfa12b0 NiPSysModifier::NiPSysModifier
#include "NiPSysModifier_fa12b0.h"

// The default constructor used by streaming: no name or target, general order, active.
NiPSysModifier::NiPSysModifier() :
    name(),
    order(ORDER::kGeneral),
    target(nullptr),
    active(true)
{
}
