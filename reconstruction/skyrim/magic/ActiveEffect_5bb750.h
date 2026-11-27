// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: adapted from the private sibling; adapted bodies: ActiveEffect::ShouldUpdate, TestBit.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:216
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffect, ActiveEffect::AdjustForPerks, ActiveEffect::OnAdd, ActiveEffect::OnRemove, ActiveEffect::GetVisualsTarget, ActiveEffect::Update, ActiveEffect::EvaluateConditions, ActiveEffect::IsCausingHealthDamage, ActiveEffect::SetLocation, ActiveEffect::SaveGame, ActiveEffect::LoadGame, ActiveEffect::FinishLoadGame, ActiveEffect::Revert, ActiveEffect::Compare, ActiveEffect::HandleEvent, ActiveEffect::SwitchAttachedRoot, ActiveEffect::HandleQueuedStart, ActiveEffect::ShouldDispelOnDeath, ActiveEffect::GetAllowMultipleCastingSourceStacking, ActiveEffect::ClearTargetImpl, ActiveEffect::~ActiveEffect, ActiveEffect::Start, ActiveEffect::Finish, ActiveEffect::CanFinish, ActiveEffect::CheckCustomSkillUseConditions, ActiveEffect::GetCustomSkillUseMagnitudeMultiplier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShouldUpdate: SIBLING(fo4-private@1b765c70, author-permission); the target is a const member returning bool
// MagicItem, MagicItem::GetSpellType, MagicSystem::SpellType::kDisease, kAbility, kAddiction, Effect, Effect::baseEffect, EffectSetting, EffectSetting::data, EffectSettingData, EffectSettingData::flags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// spell, effect, displacementSpell, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_00 to Unk_52: GUESS(low); placeholder MagicItem slots that keep the index of GetSpellType
// Actor, MagicTarget, TESObjectREFR, NiPoint3, BGSSaveFormBuffer, BGSLoadFormBuffer, BSFixedString, NiNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08, unk50, unk70, unk80: GUESS(low); members the compared function does not read
#pragma once

#include <cstdint>
#include <cstddef>

class Actor;
class MagicTarget;
class TESObjectREFR;
class NiPoint3;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class BSFixedString;
class NiNode;

// MagicSystem::SpellType: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
namespace MagicSystem
{
    enum class SpellType
    {
        kSpell = 0,
        kDisease = 1,
        kPower = 2,
        kLesserPower = 3,
        kAbility = 4,
        kPoison = 5,
        kEnchantment = 6,
        kPotion = 7,
        kWortCraft = 8,
        kLeveledSpell = 9,
        kAddiction = 10
    };
}

// MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slots below 0x53 are placeholders
class MagicItem
{
public:
    virtual void Unk_00();  // 00
    virtual void Unk_01();  // 01
    virtual void Unk_02();  // 02
    virtual void Unk_03();  // 03
    virtual void Unk_04();  // 04
    virtual void Unk_05();  // 05
    virtual void Unk_06();  // 06
    virtual void Unk_07();  // 07
    virtual void Unk_08();  // 08
    virtual void Unk_09();  // 09
    virtual void Unk_0A();  // 0A
    virtual void Unk_0B();  // 0B
    virtual void Unk_0C();  // 0C
    virtual void Unk_0D();  // 0D
    virtual void Unk_0E();  // 0E
    virtual void Unk_0F();  // 0F
    virtual void Unk_10();  // 10
    virtual void Unk_11();  // 11
    virtual void Unk_12();  // 12
    virtual void Unk_13();  // 13
    virtual void Unk_14();  // 14
    virtual void Unk_15();  // 15
    virtual void Unk_16();  // 16
    virtual void Unk_17();  // 17
    virtual void Unk_18();  // 18
    virtual void Unk_19();  // 19
    virtual void Unk_1A();  // 1A
    virtual void Unk_1B();  // 1B
    virtual void Unk_1C();  // 1C
    virtual void Unk_1D();  // 1D
    virtual void Unk_1E();  // 1E
    virtual void Unk_1F();  // 1F
    virtual void Unk_20();  // 20
    virtual void Unk_21();  // 21
    virtual void Unk_22();  // 22
    virtual void Unk_23();  // 23
    virtual void Unk_24();  // 24
    virtual void Unk_25();  // 25
    virtual void Unk_26();  // 26
    virtual void Unk_27();  // 27
    virtual void Unk_28();  // 28
    virtual void Unk_29();  // 29
    virtual void Unk_2A();  // 2A
    virtual void Unk_2B();  // 2B
    virtual void Unk_2C();  // 2C
    virtual void Unk_2D();  // 2D
    virtual void Unk_2E();  // 2E
    virtual void Unk_2F();  // 2F
    virtual void Unk_30();  // 30
    virtual void Unk_31();  // 31
    virtual void Unk_32();  // 32
    virtual void Unk_33();  // 33
    virtual void Unk_34();  // 34
    virtual void Unk_35();  // 35
    virtual void Unk_36();  // 36
    virtual void Unk_37();  // 37
    virtual void Unk_38();  // 38
    virtual void Unk_39();  // 39
    virtual void Unk_3A();  // 3A
    virtual void Unk_3B();  // 3B
    virtual void Unk_3C();  // 3C
    virtual void Unk_3D();  // 3D
    virtual void Unk_3E();  // 3E
    virtual void Unk_3F();  // 3F
    virtual void Unk_40();  // 40
    virtual void Unk_41();  // 41
    virtual void Unk_42();  // 42
    virtual void Unk_43();  // 43
    virtual void Unk_44();  // 44
    virtual void Unk_45();  // 45
    virtual void Unk_46();  // 46
    virtual void Unk_47();  // 47
    virtual void Unk_48();  // 48
    virtual void Unk_49();  // 49
    virtual void Unk_4A();  // 4A
    virtual void Unk_4B();  // 4B
    virtual void Unk_4C();  // 4C
    virtual void Unk_4D();  // 4D
    virtual void Unk_4E();  // 4E
    virtual void Unk_4F();  // 4F
    virtual void Unk_50();  // 50
    virtual void Unk_51();  // 51
    virtual void Unk_52();  // 52
    virtual MagicSystem::SpellType GetSpellType() const;  // 53
};

struct EffectSettingData
{
    std::uint32_t flags;  // 00
};

class EffectSetting
{
public:
    std::uint8_t unk00[0x68];  // 00
    EffectSettingData data;    // 68
};

struct Effect
{
    std::uint8_t unk00[0x10];  // 00
    EffectSetting* baseEffect;  // 10
};

class ActiveEffect
{
public:
    virtual void AdjustForPerks(Actor* a_caster, MagicTarget* a_target);  // 00
    virtual void OnAdd(MagicTarget* a_target);  // 01
    virtual void OnRemove();  // 02
    virtual TESObjectREFR* GetVisualsTarget();  // 03
    virtual void Update(float a_delta);  // 04
    virtual void EvaluateConditions(float a_delta, bool a_forceUpdate);  // 05
    virtual bool IsCausingHealthDamage();  // 06
    virtual void SetLocation(const NiPoint3& a_location);  // 07
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // 08
    virtual void LoadGame(BGSLoadFormBuffer* a_buf);  // 09
    virtual void FinishLoadGame(BGSLoadFormBuffer* a_buf);  // 0A
    virtual void Revert(BGSLoadFormBuffer* a_buf);  // 0B
    virtual std::int32_t Compare(ActiveEffect* a_otherEffect);  // 0C
    virtual void HandleEvent(const BSFixedString& a_eventName);  // 0D
    virtual void SwitchAttachedRoot(NiNode* a_root, NiNode* a_attachRoot);  // 0E
    virtual void HandleQueuedStart();  // 0F
    virtual bool ShouldDispelOnDeath() const;  // 10
    virtual bool GetAllowMultipleCastingSourceStacking();  // 11
    virtual void ClearTargetImpl();  // 12
    virtual ~ActiveEffect();  // 13
    virtual void Start();  // 14
    virtual void Finish();  // 15
    virtual bool CanFinish();  // 16
    virtual bool CheckCustomSkillUseConditions() const;  // 17
    virtual float GetCustomSkillUseMagnitudeMultiplier(float a_mult) const;  // 18
    bool ShouldUpdate() const;  // compared: 0x5bb750

    std::uint8_t unk08[0x38];  // 08
    MagicItem* spell;          // 40
    Effect* effect;            // 48
    std::uint8_t unk50[0x18];  // 50
    MagicItem* displacementSpell;  // 68
    std::uint8_t unk70[0xC];   // 70
    std::uint32_t flags;       // 7C
    std::uint8_t unk80[0x10];  // 80
};
static_assert(sizeof(ActiveEffect) == 0x90, "ActiveEffect size");
