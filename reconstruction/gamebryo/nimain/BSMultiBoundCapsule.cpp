// Source exposure: mixed (pinned image listing and community names).
// Code origin: existing unit plus original reconstruction of constructor, destructor, and radius getter.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x1002700 BSMultiBoundCapsule::BSMultiBoundCapsule
// 0x1002740 BSMultiBoundCapsule::GetType
// 0x1002760 BSMultiBoundCapsule::Function1002760
// 0x1002830 BSMultiBoundCapsule::~BSMultiBoundCapsule
// 0x1002880 BSMultiBoundCapsule::Function1002880
#include "BSMultiBoundCapsule.h"

BSMultiBoundCapsule::BSMultiBoundCapsule()
    : BSMultiBoundShape()
{
    centerData[0] = 0;
    centerData[1] = 0;
    centerData[2] = 0;
}

std::uint32_t BSMultiBoundCapsule::GetType() const
{
    return 0x4;
}

std::uint32_t BSMultiBoundCapsule::Function1002760(BoundCapsuleArg* a_arg)
{
    a_arg->target->Slot25();
    return 0u;
}

float BSMultiBoundCapsule::Function1002880() const
{
    return radius;
}
