// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3c7460 TESNPC::SetSkillOrBaseActorValue
// Adapted bodies: none
#include "TESNPC_3c7460.h"

// kPlayerSkillsChanged, kOwnerOffset: GUESS(low)
constexpr std::uint32_t kPlayerSkillsChanged = 0x200;
constexpr std::size_t kOwnerOffset = 0xE8;

void TESNPC::SetSkillOrBaseActorValue(std::int32_t a_actorValue, float a_value)
{
    if (a_actorValue >= 6 && a_actorValue <= 23) {
        unkA8[static_cast<std::uint32_t>(a_actorValue) - 6] = static_cast<std::uint8_t>(a_value);

        // The entry point receives the secondary actor-value subobject.
        auto& form = *reinterpret_cast<TESForm*>(reinterpret_cast<char*>(this) - kOwnerOffset);
        form.AddChange(kPlayerSkillsChanged);
    } else {
        ActorValueOwner& values = actorValues;
        values.SetBaseActorValue(a_actorValue, a_value);
    }
}
