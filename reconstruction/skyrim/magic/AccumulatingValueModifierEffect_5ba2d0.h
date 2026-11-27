// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: AccumulatingValueModifierEffect::SaveGame follows fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AccumulatingValueModifierEffect.cpp:38
// AccumulatingValueModifierEffect::SaveGame: SIBLING(fo4-private@1b765c70, author-permission)
// AccumulatingValueModifierEffect, AccumulatingValueModifierEffect::SaveGame, accumulatedMagnitude, maximumMagnitude, holdTimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffect, ValueModifierEffect, BGSSaveFormBuffer, BGSSaveGameBuffer, ActiveEffect::SaveGame, BGSSaveGameBuffer::SaveDataEndian: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; only the members the compared code uses are declared, SaveGame is slot 08 of the full class, and SaveDataEndian takes more parameters than NG declares
// unknown08, unknown90: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSSaveGameBuffer
{
public:
    void SaveDataEndian(const void* a_data, std::uint32_t a_size, std::uint32_t a_count, std::uint32_t a_arg4);
};

class BGSSaveFormBuffer : public BGSSaveGameBuffer
{
};

class ActiveEffect
{
public:
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // 08
    std::uint8_t unknown08[0x88];  // 08
};
static_assert(sizeof(ActiveEffect) == 0x90, "ActiveEffect size");

class ValueModifierEffect : public ActiveEffect
{
public:
    std::uint8_t unknown90[0x8];  // 90
};
static_assert(sizeof(ValueModifierEffect) == 0x98, "ValueModifierEffect size");

class AccumulatingValueModifierEffect : public ValueModifierEffect
{
public:
    void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 08

    float accumulatedMagnitude;  // 98
    float maximumMagnitude;      // 9C
    float holdTimer;             // A0
    std::uint32_t unknownA4;     // A4
};
static_assert(sizeof(AccumulatingValueModifierEffect) == 0xA8, "AccumulatingValueModifierEffect size");
