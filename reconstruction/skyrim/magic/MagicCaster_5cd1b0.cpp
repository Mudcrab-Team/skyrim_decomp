// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0x5cd1b0 MagicCaster::Function5cd1b0
// 0x5cd2d0 MagicCaster::Function5cd2d0
// 0x5cee80 MagicCaster::AdjustActiveEffect
// 0x5d06a0 MagicCaster::Function5d06a0
// 0x5d07a0 MagicCaster::Function5d07a0
// 0x5d07f0 MagicCaster::Function5d07f0
#include "MagicCaster_5cd1b0.h"

// GetFormForID: GUESS(low)
TESForm* GetFormForID(std::uint32_t formID);

MagicCaster* MagicCaster::Function5cd1b0(std::uint32_t formID)
{
    auto* form = GetFormForID(formID);
    if (form) {
        auto* reference = const_cast<TESObjectREFR*>(form->AsReference2());
        if (reference) {
            return reference->GetMagicCaster(static_cast<MagicSystem::CastingSource>(4));
        }
    }
    return nullptr;
}

void MagicCaster::Function5cd2d0()
{
    return SelectSpellImpl();
}

void MagicCaster::AdjustActiveEffect(ActiveEffect* effect, float power, bool option)
{
    if (effect) {
        return effect->Function5bada0(power, option);
    }
}

void MagicCaster::Function5d06a0()
{
    state = State::kUnk02;
    if (StartChargeImpl()) {
        return Function5cda50(MagicSystem::SoundID::kCharge);
    }
}

bool MagicCaster::Function5d07a0()
{
    return Function5ca880(nullptr, true);
}

void MagicCaster::Function5d07f0()
{
    state = State::kUnk04;
    if (currentSpell->GetCastingType() == MagicSystem::CastingType::kConcentration) {
        projectileTimer = 0.0f;
    }
    return StartCastImpl();
}
