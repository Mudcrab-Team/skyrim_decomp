// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicItem, ActorMagicCaster, PlayerCharacter, Actor::magicCasters, PlayerCharacter::IsCasting: CRASHLOGGER_PDB(59818@2026.10.24)
// MagicCaster::currentSpell, MagicCaster::GetCastingSource: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorMagicCaster::Unk_01 to Unk_14, ActorMagicCaster::unk08, PlayerCharacter::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class MagicItem;

class ActorMagicCaster
{
public:
    virtual ~ActorMagicCaster();
    virtual void          Unk_01();
    virtual void          Unk_02();
    virtual void          Unk_03();
    virtual void          Unk_04();
    virtual void          Unk_05();
    virtual void          Unk_06();
    virtual void          Unk_07();
    virtual void          Unk_08();
    virtual void          Unk_09();
    virtual void          Unk_0A();
    virtual void          Unk_0B();
    virtual void          Unk_0C();
    virtual void          Unk_0D();
    virtual void          Unk_0E();
    virtual void          Unk_0F();
    virtual void          Unk_10();
    virtual void          Unk_11();
    virtual void          Unk_12();
    virtual void          Unk_13();
    virtual void          Unk_14();
    virtual std::uint32_t GetCastingSource() const;  // 0x15 (0xA8)

    std::uint8_t unk08[0x20];
    MagicItem*   currentSpell;  // 0x28
};
static_assert(offsetof(ActorMagicCaster, currentSpell) == 0x28, "ActorMagicCaster::currentSpell offset");

class PlayerCharacter
{
public:
    bool IsCasting(const MagicItem* a_spell) const;

    std::uint8_t      unk00[0x1a8];
    ActorMagicCaster* magicCasters[4];  // 0x1a8
};
static_assert(offsetof(PlayerCharacter, magicCasters) == 0x1a8, "PlayerCharacter::magicCasters offset");
