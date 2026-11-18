// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x5c1260 ActorMagicCaster::SetSkipCheckCast
// 0x5c1b10 ActorMagicCaster::GetCasterStatsObject
// 0x5c2d00 ActorMagicCaster::GetIsDualCasting
// 0x5c2b80 ActorMagicCaster::ClearMagicNode
// 0x5c3110 ActorMagicCaster::SetDualCasting
// 0x5c1800 ActorMagicCaster::PrepareSound
// 0x5cdb80 ActorMagicCaster::Cast
#include "ActorMagicCaster.h"

// RVA 0x5c1260, 8 bytes, ActorMagicCaster::SetSkipCheckCast.
void ActorMagicCaster::SetSkipCheckCast()
{
    castFlags.all |= 2u;
}

// RVA 0x5c1b10, 8 bytes, ActorMagicCaster::GetCasterStatsObject.
TESObjectREFR* ActorMagicCaster::GetCasterStatsObject() const
{
    return casterStats;
}

// RVA 0x5c2d00, 10 bytes, ActorMagicCaster::GetIsDualCasting.
bool ActorMagicCaster::GetIsDualCasting() const
{
    return (castFlags.low & 1) != 0;
}

// RVA 0x5c2b80, 12 bytes, ActorMagicCaster::ClearMagicNode.
void ActorMagicCaster::ClearMagicNode()
{
    magicNode = nullptr;
}

// RVA 0x5c3110, 31 bytes, ActorMagicCaster::SetDualCasting.
// The bit is set or cleared from the same starting value.
void ActorMagicCaster::SetDualCasting(bool a_set)
{
    const std::uint32_t current = castFlags.all;
    castFlags.all = a_set ? (current | 1u) : (current & 0xFFFFFFFEu);
}

// RVA 0x5c1800, 42 bytes, ActorMagicCaster::PrepareSound.
// With no spell given, the spell in the caster's slot is used when the slot index is in range.
void ActorMagicCaster::PrepareSound(MagicSystem::SoundID a_sound, MagicItem* a_spell)
{
    if (a_spell == nullptr) {
        TESObjectREFR* stats = casterStats;
        if (stats != nullptr && static_cast<std::uint32_t>(slotIndex) <= 3u) {
            a_spell = stats->spellSlots[slotIndex];
        }
    }
    PlaySpellSound(a_sound, a_spell);
}

// RVA 0x5cdb80, 50 bytes, ActorMagicCaster::Cast.
// The cast state is set before the readiness check; a ready caster starts the cast.
void ActorMagicCaster::Cast()
{
    castState = 2;
    if (IsCastReady()) {
        StartCast(1u);
    }
}

// Accepted leaf retained from the integrated version.
// GetCastingSource: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint32_t ActorMagicCaster::GetCastingSource() const
{
    return static_cast<std::uint32_t>(slotIndex);
}
