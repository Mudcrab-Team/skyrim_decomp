// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing leaf plus original reconstruction of Function1002760.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1002740 BSMultiBoundCapsule::GetType
// 0x1002760 BSMultiBoundCapsule::Function1002760
#include "BSMultiBoundCapsule.h"

std::uint32_t BSMultiBoundCapsule::GetType() const
{
    return 0x4;
}

std::uint32_t BSMultiBoundCapsule::Function1002760(BoundCapsuleArg* a_arg)
{
    a_arg->target->Slot25();
    return 0u;
}
