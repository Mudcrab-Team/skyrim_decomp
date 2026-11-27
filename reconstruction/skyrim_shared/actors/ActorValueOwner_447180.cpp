// Source exposure: mixed (community headers; the pinned image listing; permitted sibling bodies).
// Code origin: bodies adapted from permitted siblings, flag bits and constants checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x447180 ActorValueOwner::GetClampedActorValue
// Adapted bodies: ActorValueOwner::GetClampedActorValue (fo4 shape), ActorValueInfo::ClampActorValue (fnv shape, in the header)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/actorvalue.cpp:196
// Sibling source: fo4-private@1b765c70 src/Shared/AI/ActorValueOwner.cpp:12
#include "ActorValueOwner_447180.h"

// The owner's current value of one actor value, limited by the limits its info record sets.
float ActorValueOwner::GetClampedActorValue(ActorValue a_akValue)
{
    float value = GetActorValue(a_akValue);
    ActorValueInfo* info = ActorValueList::singleton->actorValues[static_cast<std::int32_t>(a_akValue)];
    return info->ClampActorValue(value);
}
