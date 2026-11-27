// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicItem, ActorMagicCaster, Actor, Actor::magicCasters, Actor::CheckCast_140631CE0: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorMagicCaster::CheckCast: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorMagicCaster::Unk_01 to Unk_09, Actor::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class MagicItem;

class ActorMagicCaster
{
public:
    virtual ~ActorMagicCaster();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual bool CheckCast(MagicItem* a_spell, bool a_dualCast, float* a_effectStrength, std::uint32_t* a_reason, bool a_useBaseValueForCost);  // 0x0a
};

class Actor
{
public:
    bool CheckCast_140631CE0(MagicItem* a_spell, bool a_dualCast, std::uint32_t* a_reason);

    std::uint8_t      unk00[0x1a8];
    ActorMagicCaster* magicCasters[4];  // 0x1a8
};
static_assert(offsetof(Actor, magicCasters) == 0x1a8, "Actor::magicCasters offset");
