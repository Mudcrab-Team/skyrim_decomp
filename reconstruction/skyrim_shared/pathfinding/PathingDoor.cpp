// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x4e0f40 PathingDoor::Function4e0f40
// Adapted bodies: none
// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x4e0ee0 PathingDoor::Function4e0ee0
// Adapted bodies: none
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PathingDoor","rationale":"vtable owner and slot; method spelling invented","slot":2},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// PathingDoor: EXE_RTTI
// Slot2: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#include "PathingDoor.h"
// Slot2: GUESS(low); method name inferred from vtable owner and slot
std::uint32_t PathingDoor::Slot2() const
{
    return member;
}

void PathingDoor::Function4e0ee0(PathingDoorTarget* a_target)
{
    a_target->SetValue(member);
}

void PathingDoor::Function4e0f40(PathingDoorTarget* a_target)
{
    a_target->Slot01(&member);
}
