// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: adapted from the private sibling; adapted bodies: SpellItem::GetChargeTime.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:189
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SpellItem, SpellItem::~SpellItem, SpellItem::InitializeData, SpellItem::GetMenuDisplayObject, SpellItem::ClearData, SpellItem::InitItemImpl, SpellItem::GetSpellType, SpellItem::SetCastingType, SpellItem::GetCastingType, SpellItem::SetDelivery, SpellItem::GetDelivery, SpellItem::GetFixedCastDuration, SpellItem::GetRange, SpellItem::IgnoresResistance, SpellItem::IgnoreLOS, SpellItem::GetNoAbsorb, SpellItem::GetNoDualCastModifications, SpellItem::GetSkillUsageData, SpellItem::AdjustCost, SpellItem::GetChargeTime, SpellItem::GetAssociatedSkill, SpellItem::IsTwoHanded, SpellItem::GetChunkID, SpellItem::CopyMagicItemData, SpellItem::LoadMagicItemChunk, SpellItem::LoadChunkDataPostProcess, SpellItem::GetData1, SpellItem::GetData2, SpellItem::GetDataSize, SpellItem::InitFromChunk, SpellItem::InitChunk, TESObject::~TESObject, TESObject::IsObject, TESObject::GetRefCount, TESObject::Unk_3B, TESObject::IsBoundAnimObject, TESObject::GetWaterType, TESObject::IsAutoCalc, TESObject::SetAutoCalc, TESObject::Clone3D, TESObject::UnClone3D, TESObject::IsMarker, TESObject::IsOcclusionMarker, TESObject::ReplaceModel, TESObject::IncRef, TESObject::DecRef, TESObject::LoadGraphics, TESBoundObject::~TESBoundObject, TESBoundObject::LoadObjectBound, TESBoundObject::IsBoundObject, TESBoundObject::Activate, TESBoundObject::Clone3D, TESBoundObject::ReplaceModel, TESBoundObject::SetObjectVoiceType, TESBoundObject::GetObjectVoiceType, TESBoundObject::GetActivateText, TESBoundObject::CalculateDoFavor, TESBoundObject::HandleRemoveItemFromContainer, TESBoundObject::OnRemove3D, TESBoundObject::OnCheckModels, TESBoundObject::OnCopyReference, TESBoundObject::OnFinishScale, MagicItem::~MagicItem, MagicItem::InitializeData, MagicItem::HasKeyword, MagicItem::Load, MagicItem::InitItemImpl, MagicItem::IsMagicItem, MagicItem::Copy, MagicItem::IsAutoCalc, MagicItem::GetSpellType, MagicItem::SetCastingType, MagicItem::GetCastingType, MagicItem::SetDelivery, MagicItem::GetDelivery, MagicItem::IsValidDelivery, MagicItem::GetFixedCastDuration, MagicItem::GetRange, MagicItem::IgnoresResistance, MagicItem::IgnoreLOS, MagicItem::IsFood, MagicItem::GetNoAbsorb, MagicItem::GetNoDualCastModifications, MagicItem::GetSkillUsageData, MagicItem::IsPoison, MagicItem::IsMedicine, MagicItem::AdjustCost, MagicItem::GetChargeTime, MagicItem::GetMaxEffectCount, MagicItem::GetAssociatedSkill, MagicItem::IsTwoHanded, MagicItem::GetChunkID, MagicItem::CopyMagicItemData, MagicItem::LoadMagicItemChunk, MagicItem::LoadChunkDataPostProcess, MagicItem::GetData1, MagicItem::GetData2, MagicItem::GetDataSize, MagicItem::InitFromChunk, MagicItem::InitChunk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObject, TESBoundObject, MagicItem, SkillUsageData, Actor, TESWaterForm, NiAVObject, BGSVoiceType, BSString, BGSKeyword, Data: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// effects, data, chargeTime, spellmakingChargeTime, baseEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk0C, unk14, tailData, flagsLow, flagBit24, flagsHigh: GUESS(low)
// unknown20, unk30, unk70, unk90: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

struct SkillUsageData;
class Actor;
class TESWaterForm;
class NiAVObject;
class BGSVoiceType;
class BSString;
class BGSKeyword;
class Effect;

// ActorValue, MagicSystem::SpellType, CastingType, Delivery: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); opaque enums, only named in signatures
enum class ActorValue : std::int32_t;
namespace MagicSystem
{
    enum class SpellType : std::int32_t;
    enum class CastingType : std::int32_t;
    enum class Delivery : std::int32_t;
}

// BSTArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the layout with the default heap allocator
template <class T>
class BSTArray
{
public:
    T* _data;  // 00
    std::uint32_t _capacity;  // 08
    std::uint32_t unk0C;  // 0C
    std::uint32_t _size;  // 10
    std::uint32_t unk14;  // 14

    std::uint32_t size() const { return _size; }
    T& operator[](std::uint32_t a_pos) { return _data[a_pos]; }
    const T& operator[](std::uint32_t a_pos) const { return _data[a_pos]; }
};
static_assert(sizeof(BSTArray<Effect*>) == 0x18, "BSTArray size");

// Effect, EffectSetting, EffectSettingData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members GetChargeTime reads
// unk00, unk04, unk10, unk6C, unkB4: GUESS(low)
struct EffectSettingData
{
    // the flag word is viewed byte-wise so that bit 24 is a bit-field of its own (cookbook rule 52)
    std::uint8_t flagsLow[3];      // 00
    std::uint8_t flagBit24 : 1;    // 03
    std::uint8_t flagsHigh : 7;    // 03
    std::uint8_t unk04[0x44];  // 04
    float spellmakingChargeTime;  // 48
    std::uint8_t unk4C[0x4];  // 4C
};

class EffectSetting
{
public:
    std::uint8_t unk00[0x68];  // 00
    EffectSettingData data;  // 68
};

class Effect
{
public:
    std::uint8_t unk00[0x10];  // 00
    EffectSetting* baseEffect;  // 10
};

// The equip type, menu display object and description bases at 90 to C0 are padding here; no compared function reads them.

class TESObject : public TESForm
{
public:
    ~TESObject() override;  // 00
    bool IsObject() const override;  // 28
    std::uint32_t GetRefCount() const override;  // 2D
    virtual void Unk_3B(void);  // 3B
    virtual bool IsBoundAnimObject();  // 3C
    virtual TESWaterForm* GetWaterType() const;  // 3D
    virtual bool IsAutoCalc() const;  // 3E
    virtual void SetAutoCalc(bool a_autoCalc);  // 3F
    virtual NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3);  // 40
    virtual void UnClone3D(TESObjectREFR* a_ref);  // 41
    virtual bool IsMarker();  // 42
    virtual bool IsOcclusionMarker();  // 43
    virtual bool ReplaceModel();  // 44
    virtual std::uint32_t IncRef();  // 45
    virtual std::uint32_t DecRef();  // 46
    virtual NiAVObject* LoadGraphics(TESObjectREFR* a_ref);  // 47
};
static_assert(sizeof(TESObject) == 0x20, "TESObject size");

class TESBoundObject : public TESObject
{
public:
    ~TESBoundObject() override;  // 00
    void LoadObjectBound(TESFile* a_mod) override;  // 26
    bool IsBoundObject() const override;  // 27
    bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
    NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;  // 40
    bool ReplaceModel() override;  // 44
    virtual void SetObjectVoiceType(BGSVoiceType* a_voiceType);  // 48
    virtual BGSVoiceType* GetObjectVoiceType() const;  // 49
    virtual NiAVObject* Clone3D(TESObjectREFR* a_ref);  // 4A
    virtual bool ReplaceModel(const char* a_str);  // 4B
    virtual bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst);  // 4C
    virtual bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3);  // 4D
    virtual void HandleRemoveItemFromContainer(TESObjectREFR* a_container);  // 4E
    virtual void OnRemove3D(NiAVObject* a_obj3D);  // 4F
    virtual void OnCheckModels();  // 50
    virtual void OnCopyReference();  // 51
    virtual void OnFinishScale();  // 52
    std::uint8_t unknown20[0x10];  // 20
};
static_assert(sizeof(TESBoundObject) == 0x30, "TESBoundObject size");

class MagicItem : public TESBoundObject
{
public:
    class Data;

    ~MagicItem() override;  // 00
    void InitializeData() override;  // 04
    bool Load(TESFile* a_mod) override;  // 06
    void InitItemImpl() override;  // 13
    bool IsMagicItem() const override;  // 29
    void Copy(TESForm* a_srcForm) override;  // 2F
    bool IsAutoCalc() const override;  // 3E
    virtual MagicSystem::SpellType GetSpellType() const = 0;  // 53
    virtual void SetCastingType(MagicSystem::CastingType a_type);  // 54
    virtual MagicSystem::CastingType GetCastingType() const = 0;  // 55
    virtual void SetDelivery(MagicSystem::Delivery a_delivery);  // 56
    virtual MagicSystem::Delivery GetDelivery() const = 0;  // 57
    virtual bool IsValidDelivery(MagicSystem::Delivery a_delivery);  // 58
    virtual float GetFixedCastDuration() const;  // 59
    virtual float GetRange() const;  // 5A
    virtual bool IgnoresResistance() const;  // 5B
    virtual bool IgnoreLOS() const;  // 5C
    virtual bool IsFood() const;  // 5D
    virtual bool GetNoAbsorb() const;  // 5E
    virtual bool GetNoDualCastModifications() const;  // 5F
    virtual bool GetSkillUsageData(SkillUsageData& a_data) const;  // 60
    virtual bool IsPoison() const;  // 61
    virtual bool IsMedicine() const;  // 62
    virtual void AdjustCost(float& a_cost, Actor* a_actor) const;  // 63
    virtual float GetChargeTime() const;  // 64
    virtual std::uint32_t GetMaxEffectCount() const;  // 65
    virtual ActorValue GetAssociatedSkill() const;  // 66
    virtual bool IsTwoHanded() const;  // 67
    virtual std::uint32_t GetChunkID() = 0;  // 68
    virtual void CopyMagicItemData(MagicItem* a_src) = 0;  // 69
    virtual void LoadMagicItemChunk(TESFile* a_mod, std::uint32_t a_chunkID);  // 6A
    virtual void LoadChunkDataPostProcess(TESFile* a_mod);  // 6B
    virtual const Data* GetData1() const = 0;  // 6C
    virtual Data* GetData2() = 0;  // 6D
    virtual std::uint32_t GetDataSize() const = 0;  // 6E
    virtual void InitFromChunk(TESFile* a_mod) = 0;  // 6F
    virtual void InitChunk() = 0;  // 70
    std::uint8_t unk30[0x28];  // 30
    BSTArray<Effect*> effects;  // 58
    std::uint8_t unk70[0x20];  // 70
};
static_assert(sizeof(MagicItem) == 0x90, "MagicItem size");

class SpellItem : public MagicItem
{
public:
    ~SpellItem() override;  // 00
    void InitializeData() override;  // 04
    void ClearData() override;  // 05
    void InitItemImpl() override;  // 13
    MagicSystem::SpellType GetSpellType() const override;  // 53
    void SetCastingType(MagicSystem::CastingType a_type) override;  // 54
    MagicSystem::CastingType GetCastingType() const override;  // 55
    void SetDelivery(MagicSystem::Delivery a_type) override;  // 56
    MagicSystem::Delivery GetDelivery() const override;  // 57
    float GetFixedCastDuration() const override;  // 59
    float GetRange() const override;  // 5A
    bool IgnoresResistance() const override;  // 5B
    bool IgnoreLOS() const override;  // 5C
    bool GetNoAbsorb() const override;  // 5E
    bool GetNoDualCastModifications() const override;  // 5F
    bool GetSkillUsageData(SkillUsageData& a_data) const override;  // 60
    void AdjustCost(float& a_cost, Actor* a_actor) const override;  // 63
    float GetChargeTime() const override;  // 64
    ActorValue GetAssociatedSkill() const override;  // 66
    bool IsTwoHanded() const override;  // 67
    std::uint32_t GetChunkID() override;  // 68
    void CopyMagicItemData(MagicItem* a_src) override;  // 69
    void LoadMagicItemChunk(TESFile* a_mod, std::uint32_t a_chunkID) override;  // 6A
    void LoadChunkDataPostProcess(TESFile* a_mod) override;  // 6B
    const MagicItem::Data* GetData1() const override;  // 6C
    MagicItem::Data* GetData2() override;  // 6D
    std::uint32_t GetDataSize() const override;  // 6E
    void InitFromChunk(TESFile* a_mod) override;  // 6F
    void InitChunk() override;  // 70

    // SpellItem::Data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the SPIT block, only chargeTime is read
    class Data
    {
    public:
        std::int32_t costOverride;  // 00
        std::uint32_t flags;  // 04
        std::int32_t spellType;  // 08
        float chargeTime;  // 0C
        std::uint8_t tailData[0x18];  // 10
    };
    static_assert(sizeof(Data) == 0x28, "SpellItem::Data size");

    std::uint8_t unk90[0x30];  // 90
    Data data;  // C0
};
static_assert(sizeof(SpellItem) == 0xE8, "SpellItem size");
