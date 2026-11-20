// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// ActorMagicCaster: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// MagicCaster: STANDIN EXE_RTTI
// ActorMagicCaster::SetSkipCheckCast, ActorMagicCaster::GetCasterStatsObject, ActorMagicCaster::GetIsDualCasting, ActorMagicCaster::ClearMagicNode, ActorMagicCaster::SetDualCasting, ActorMagicCaster::PrepareSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR, MagicSystem::SoundID, MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorMagicCaster::Cast: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESObjectREFR::spellSlots: GUESS(low); four item pointers at +0x1C8 that PrepareSound falls back to, read through the object at the caster's +0xB8
// MagicCaster::vslot01, MagicCaster::vslot02, MagicCaster::vslot03: GUESS(low); placeholder virtual slots so that IsCastReady sits at vtable offset 0x20
// MagicCaster::IsCastReady: GUESS(low); the virtual check at vtable offset 0x20 that Cast takes a boolean from
// MagicCaster::castState: GUESS(low); the dword at +0x30 that Cast sets to 2 before the check
// MagicCaster::pad08, MagicCaster::pad34: GUESS(low); padding the listing does not touch
// ActorMagicCaster::magicNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares it in ActorMagicCaster at another offset; the pointer here sits at +0xC0
// ActorMagicCaster::unk48, ActorMagicCaster::casterStats, ActorMagicCaster::unkC8, ActorMagicCaster::slotIndex, ActorMagicCaster::unkFC: GUESS(low); casterStats is the pointer at +0xB8, slotIndex the signed index at +0xF4
// ActorCastFlags, ActorCastFlags::all, ActorCastFlags::low: GUESS(low); the flags dword at +0xF8, read as a dword in three functions and as its low byte in GetIsDualCasting
// ActorMagicCaster::PlaySpellSound: GUESS(low); the callee at RVA 0x5cd990 that PrepareSound tail-calls with the resolved spell
// ActorMagicCaster::StartCast: GUESS(low); the callee at RVA 0x5cda50 that Cast tail-calls with true
#pragma once

#include <cstdint>
#include <cstddef>

class MagicItem;

namespace MagicSystem { enum class SoundID : int; }

class TESObjectREFR
{
public:
    std::uint8_t unk00[0x1C8];   // 00
    MagicItem*   spellSlots[4];  // 1C8
};

class MagicCaster
{
public:
    virtual ~MagicCaster() = default;
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual bool IsCastReady();  // slot 0x04

    std::uint8_t pad08[0x28];  // 08
    std::int32_t castState;    // 30
    std::uint8_t pad34[0x14];  // 34
};
static_assert(sizeof(MagicCaster) == 0x48, "MagicCaster size");

union ActorCastFlags
{
    std::uint32_t all;  // 00
    std::uint8_t  low;  // 00
};

class ActorMagicCaster : public MagicCaster
{
public:
    virtual std::uint32_t GetCastingSource() const;
    virtual void SetSkipCheckCast();  // compared: 0x5c1260
    virtual TESObjectREFR* GetCasterStatsObject() const;  // compared: 0x5c1b10
    virtual bool GetIsDualCasting() const;  // compared: 0x5c2d00
    virtual void ClearMagicNode();  // compared: 0x5c2b80
    virtual void SetDualCasting(bool a_set);  // compared: 0x5c3110
    virtual void PrepareSound(MagicSystem::SoundID a_sound, MagicItem* a_spell);  // compared: 0x5c1800
    void Cast();  // compared: 0x5cdb80
    void PlaySpellSound(MagicSystem::SoundID a_sound, MagicItem* a_spell);
    void StartCast(std::uint32_t a_flag);

    std::uint8_t    unk48[0x70];    // 48
    TESObjectREFR*  casterStats;    // B8
    MagicItem*      magicNode;      // C0
    std::uint8_t    unkC8[0x2C];    // C8
    std::int32_t    slotIndex;      // F4
    ActorCastFlags  castFlags;      // F8
    std::uint8_t    unkFC[0x4];     // FC
};
static_assert(sizeof(ActorMagicCaster) == 0x100, "ActorMagicCaster size");
