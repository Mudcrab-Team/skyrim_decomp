// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; class prefixes, member names
// and virtual-slot order follow the cited community declarations.
// ActorMagicCaster: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// MagicCaster: STANDIN EXE_RTTI
// ActorMagicCaster::SetSkipCheckCast, ActorMagicCaster::GetCasterStatsObject, ActorMagicCaster::GetIsDualCasting, ActorMagicCaster::ClearMagicNode, ActorMagicCaster::SetDualCasting, ActorMagicCaster::PrepareSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR, MagicSystem::SoundID, MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorMagicCaster::Cast: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESObjectREFR::spellSlots: GUESS(low); four item pointers at +0x1C8 that PrepareSound falls back to, read through the object at the caster's +0xB8
// MagicCaster::currentSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the item pointer at +0x28 that Function5c15e0 tests
// MagicCaster::FinishLoadGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares it as the virtual slot 0x1A with a buffer argument, and the listing shows a call with this only
// MagicCaster::PrepareCastingSounds: GUESS(low); the MagicCaster callee that Function5c15e0 calls with one MagicItem*
// TESObjectREFR::actorState2: GUESS(low); the dword at +0xCC, named after the actor state member the pinned headers declare, whose 0xE0 mask is compared with 0x60
// TESObjectREFR::Function6d7770: GUESS(low); the unnamed callee at RVA 0x6d7770, declared on the reference prefix because the caster reaches the actor through a TESObjectREFR pointer
// TESObjectREFR::unknown00 .. unknownC0, unknownC8, unknownD0 .. unknown1C0: GUESS(low); the reference prefix on either side of actorState2 that no compared function in this unit reads, typed at 8-byte and dword width at its real offsets
// MagicCaster::vslot01, MagicCaster::vslot02, MagicCaster::vslot03: GUESS(low); placeholder virtual slots so that IsCastReady sits at vtable offset 0x20
// MagicCaster::IsCastReady: GUESS(low); the virtual check at vtable offset 0x20 that Cast takes a boolean from
// MagicCaster::castState: GUESS(low); the dword at +0x30 that Cast sets to 2 before the check
// MagicCaster::unknown08 .. unknown20, unknown34 .. unknown40: GUESS(low); the ranges around currentSpell and castState that no compared function in this unit reads, typed at 8-byte and dword width at their real offsets
// ActorMagicCaster::magicNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares it in ActorMagicCaster at another offset; the pointer here sits at +0xC0
// ActorMagicCaster::casterStats, ActorMagicCaster::slotIndex: GUESS(low); casterStats is the pointer at +0xB8, slotIndex the signed index at +0xF4
// ActorMagicCaster::unknown48 .. unknownB0, unknownC8 .. unknownF0, unknownFC: GUESS(low); the ranges between the base and the caster fields that no compared function in this unit reads, typed at 8-byte and dword width at their real offsets
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
    void Function6d7770(std::int32_t a_source, bool a_first, bool a_second);

    std::uint64_t unknown00;  // 00
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
    std::uint64_t unknown78;  // 78
    std::uint64_t unknown80;  // 80
    std::uint64_t unknown88;  // 88
    std::uint64_t unknown90;  // 90
    std::uint64_t unknown98;  // 98
    std::uint64_t unknownA0;  // A0
    std::uint64_t unknownA8;  // A8
    std::uint64_t unknownB0;  // B0
    std::uint64_t unknownB8;  // B8
    std::uint64_t unknownC0;  // C0
    std::uint32_t unknownC8;  // C8
    std::uint32_t actorState2; // CC
    std::uint64_t unknownD0;  // D0
    std::uint64_t unknownD8;  // D8
    std::uint64_t unknownE0;  // E0
    std::uint64_t unknownE8;  // E8
    std::uint64_t unknownF0;  // F0
    std::uint64_t unknownF8;  // F8
    std::uint64_t unknown100; // 100
    std::uint64_t unknown108; // 108
    std::uint64_t unknown110; // 110
    std::uint64_t unknown118; // 118
    std::uint64_t unknown120; // 120
    std::uint64_t unknown128; // 128
    std::uint64_t unknown130; // 130
    std::uint64_t unknown138; // 138
    std::uint64_t unknown140; // 140
    std::uint64_t unknown148; // 148
    std::uint64_t unknown150; // 150
    std::uint64_t unknown158; // 158
    std::uint64_t unknown160; // 160
    std::uint64_t unknown168; // 168
    std::uint64_t unknown170; // 170
    std::uint64_t unknown178; // 178
    std::uint64_t unknown180; // 180
    std::uint64_t unknown188; // 188
    std::uint64_t unknown190; // 190
    std::uint64_t unknown198; // 198
    std::uint64_t unknown1A0; // 1A0
    std::uint64_t unknown1A8; // 1A8
    std::uint64_t unknown1B0; // 1B0
    std::uint64_t unknown1B8; // 1B8
    std::uint64_t unknown1C0; // 1C0
    MagicItem*    spellSlots[4]; // 1C8
};

class MagicCaster
{
public:
    virtual ~MagicCaster() = default;
    virtual void vslot01();
    virtual void vslot02();
    virtual void vslot03();
    virtual bool IsCastReady();  // slot 0x04

    void FinishLoadGame();                          // MagicCaster implementation called by the compared function
    void PrepareCastingSounds(MagicItem* a_spell);  // MagicCaster implementation called by the compared function

    std::uint64_t unknown08;   // 08
    std::uint64_t unknown10;   // 10
    std::uint64_t unknown18;   // 18
    std::uint64_t unknown20;   // 20
    MagicItem*    currentSpell; // 28
    std::int32_t  castState;   // 30
    std::uint32_t unknown34;   // 34
    std::uint64_t unknown38;   // 38
    std::uint64_t unknown40;   // 40
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
    void Function5c15e0();  // compared: 0x5c15e0
    void PlaySpellSound(MagicSystem::SoundID a_sound, MagicItem* a_spell);
    void StartCast(std::uint32_t a_flag);

    std::uint64_t   unknown48;   // 48
    std::uint64_t   unknown50;   // 50
    std::uint64_t   unknown58;   // 58
    std::uint64_t   unknown60;   // 60
    std::uint64_t   unknown68;   // 68
    std::uint64_t   unknown70;   // 70
    std::uint64_t   unknown78;   // 78
    std::uint64_t   unknown80;   // 80
    std::uint64_t   unknown88;   // 88
    std::uint64_t   unknown90;   // 90
    std::uint64_t   unknown98;   // 98
    std::uint64_t   unknownA0;   // A0
    std::uint64_t   unknownA8;   // A8
    std::uint64_t   unknownB0;   // B0
    TESObjectREFR*  casterStats; // B8
    MagicItem*      magicNode;   // C0
    std::uint64_t   unknownC8;   // C8
    std::uint64_t   unknownD0;   // D0
    std::uint64_t   unknownD8;   // D8
    std::uint64_t   unknownE0;   // E0
    std::uint64_t   unknownE8;   // E8
    std::uint32_t   unknownF0;   // F0
    std::int32_t    slotIndex;   // F4
    ActorCastFlags  castFlags;   // F8
    std::uint32_t   unknownFC;   // FC
};
static_assert(sizeof(ActorMagicCaster) == 0x100, "ActorMagicCaster size");
