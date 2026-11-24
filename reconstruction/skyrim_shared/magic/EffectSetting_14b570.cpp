// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14b570 EffectSetting::GetSound
// Adapted bodies: none
#include "EffectSetting_14b570.h"

BGSSoundDescriptorForm* EffectSetting::GetSound(MagicSystem::SoundID a_id) const
{
    BGSSoundDescriptorForm* sound = nullptr;
    for (std::uint32_t i = 0; !sound && i < effectSounds.size; ++i) {
        if (effectSounds.data[i].id == a_id) {
            sound = effectSounds.data[i].sound;
        }
    }
    return sound;
}
