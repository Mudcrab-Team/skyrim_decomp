// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EffectSetting, EffectSetting::SoundPair, EffectSetting::effectSounds, MagicSystem::SoundID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EffectSetting::GetSound: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSSoundDescriptorForm;

namespace MagicSystem
{
    enum class SoundID
    {
        kDrawSheatheLPM = 0,
        kCharge = 1,
        kReadyLoop = 2,
        kRelease = 3,
        kCastLoop = 4,
        kHit = 5
    };
}

class EffectSetting
{
public:
    struct SoundPair
    {
        MagicSystem::SoundID id;
        std::uint32_t pad04;
        BGSSoundDescriptorForm* sound;
    };
    static_assert(sizeof(SoundPair) == 0x10, "SoundPair size");

    // BSTArray<SoundPair>: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    struct SoundArray
    {
        SoundPair* data;
        std::uint32_t capacity;
        std::uint32_t pad0C;
        std::uint32_t size;
        std::uint32_t pad14;
    };

    BGSSoundDescriptorForm* GetSound(MagicSystem::SoundID a_id) const;  // compared: 0x14b570

    std::uint8_t pad000[0x168];
    SoundArray effectSounds;
};
static_assert(offsetof(EffectSetting, effectSounds) == 0x168, "effectSounds offset");
