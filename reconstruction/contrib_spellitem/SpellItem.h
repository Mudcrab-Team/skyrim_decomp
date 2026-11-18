// Source exposure: mixed
// SpellItem, MagicItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/S/SpellItem.h, include/RE/M/MagicItem.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h, include/RE/T/TESFullName.h and include/RE/B/BGSKeywordForm.h, include/RE/B/BGSEquipType.h, include/RE/B/BGSMenuDisplayObject.h and include/RE/T/TESDescription.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SpellItem::GetDelivery, GetFixedCastDuration, IgnoresResistance, GetData2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// SpellItemData, unk08, data: STANDIN GUESS(low); the record at 0xC0 and only the members the compared code reads
// unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78, unk80, unk88, unk90, unk98, unkA0, unkA8, unkB0, unkB8: GUESS(low); storage before data, where the community class has base subobjects and members
#pragma once
#include <cstdint>
class TESFile; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class TESObjectREFR; class BSFixedString; struct FORM; struct FORM_GROUP; class TESBoundObject; class TESWaterForm; class NiAVObject; class BGSVoiceType; class BSString; class Actor;
using FormID = std::uint32_t; enum class FormType : unsigned char; enum class ActorValue : int;
namespace MagicSystem { enum class SpellType : int; enum class CastingType : int; enum class Delivery : int; }
class Component { public: virtual ~Component(); virtual void InitializeDataComponent(); virtual void ClearDataComponent(); virtual void CopyComponent(Component*); };
class TESForm : public Component { public:
virtual void                               InitializeData();
virtual void                               ClearData();
virtual bool                               Load(TESFile* a_mod);
virtual bool                               LoadPartial(TESFile* a_mod);
virtual bool                               LoadEdit(TESFile* a_mod);
virtual TESForm*                           CreateDuplicateForm(bool a_createEditorID, void* a_arg2);
virtual bool                               AddChange(std::uint32_t a_changeFlags);
virtual void                               RemoveChange(std::uint32_t a_changeFlags);
virtual bool                               FindInFileFast(TESFile* a_mod);
virtual bool                               CheckSaveGame(BGSSaveFormBuffer* a_buf);
virtual void                               SaveGame(BGSSaveFormBuffer* a_buf);
virtual void                               LoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               InitLoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               FinishLoadGame(BGSLoadFormBuffer* a_buf);
virtual void                               Revert(BGSLoadFormBuffer* a_buf);
virtual void                               InitItemImpl();
virtual TESFile*             GetDescriptionOwnerFile() const;
virtual FormType             GetSavedFormType() const;
virtual void                               GetFormDetailedString(char* a_buf, std::uint32_t a_bufLen);
virtual bool                 GetKnown() const;
virtual bool                 GetRandomAnim() const;
virtual bool                 GetPlayable() const;
virtual bool                 IsHeadingMarker() const;
virtual bool                 GetDangerous() const;
virtual bool                 QHasCurrents() const;
virtual bool                 GetObstacle() const;
virtual bool                 QIsLODLandObject() const;
virtual bool                 GetOnLocalMap() const;
virtual bool                 GetMustUpdate() const;
virtual void                               SetOnLocalMap(bool a_set);
virtual bool                 GetIgnoredBySandbox() const;
virtual void                               SetDelete(bool a_set);
virtual void                               SetAltered(bool a_set);
virtual void                               SaveObjectBound();
virtual void                               LoadObjectBound(TESFile* a_mod);
virtual bool                 IsBoundObject() const;
virtual bool                 IsObject() const;
virtual bool                 IsMagicItem() const;
virtual bool                 IsWater() const;
virtual TESObjectREFR*                     AsReference1();
virtual const TESObjectREFR* AsReference2() const;
virtual std::uint32_t        GetRefCount() const;
virtual const char*          GetTextForParsedSubTag(const BSFixedString& a_tag) const;
virtual void                               Copy(TESForm* a_srcForm);
virtual bool                               BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly);
virtual void                               CreateGroupData(FORM* a_form, FORM_GROUP* a_group);
virtual const char*          GetFormEditorID() const;
virtual bool                               SetFormEditorID(const char* a_str);
virtual bool                               IsParentForm();
virtual bool                               IsParentFormTree();
virtual bool                               IsFormTypeChild(FormType a_type);
virtual bool                               Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount);
virtual void                               SetFormID(FormID a_id, bool a_updateFile);
virtual const char*          GetObjectTypeName() const;
virtual bool                 QAvailableInGame() const;
};
class TESObject : public TESForm { public:
virtual void                        Unk_3B(void);
virtual bool                        IsBoundAnimObject();
virtual TESWaterForm* GetWaterType() const;
virtual bool          IsAutoCalc() const;
virtual void                        SetAutoCalc(bool a_autoCalc);
virtual NiAVObject*                 Clone3D(TESObjectREFR* a_ref, bool a_arg3);
virtual void                        UnClone3D(TESObjectREFR* a_ref);
virtual bool                        IsMarker();
virtual bool                        IsOcclusionMarker();
virtual bool                        ReplaceModel();
virtual std::uint32_t               IncRef();
virtual std::uint32_t               DecRef();
virtual NiAVObject*                 LoadGraphics(TESObjectREFR* a_ref);
};
class TESBoundObject : public TESObject { public:
virtual void                        SetObjectVoiceType(BGSVoiceType* a_voiceType);
virtual BGSVoiceType* GetObjectVoiceType() const;
virtual NiAVObject*                 Clone3D(TESObjectREFR* a_ref);
virtual bool                        ReplaceModel(const char* a_str);
virtual bool                        GetActivateText(TESObjectREFR* a_activator, BSString& a_dst);
virtual bool                        CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3);
virtual void                        HandleRemoveItemFromContainer(TESObjectREFR* a_container);
virtual void                        OnRemove3D(NiAVObject* a_obj3D);
virtual void                        OnCheckModels();
virtual void                        OnCopyReference();
virtual void                        OnFinishScale();
};
class MagicItem : public TESBoundObject { public: struct Data { int costOverride; unsigned flags; }; struct SkillUsageData;
virtual MagicSystem::SpellType   GetSpellType() const = 0;
virtual void                                   SetCastingType(MagicSystem::CastingType a_type);
virtual MagicSystem::CastingType GetCastingType() const = 0;
virtual void                                   SetDelivery(MagicSystem::Delivery a_delivery);
virtual MagicSystem::Delivery    GetDelivery() const = 0;
virtual bool                     IsValidDelivery(MagicSystem::Delivery a_delivery);
virtual float                    GetFixedCastDuration() const;
virtual float                    GetRange() const;
virtual bool                     IgnoresResistance() const;
virtual bool                     IgnoreLOS() const;
virtual bool                     IsFood() const;
virtual bool                     GetNoAbsorb() const;
virtual bool                     GetNoDualCastModifications() const;
virtual bool                                   GetSkillUsageData(SkillUsageData& a_data) const;
virtual bool                     IsPoison() const;
virtual bool                     IsMedicine() const;
virtual void                                   AdjustCost(float& a_cost, Actor* a_actor) const;
virtual float                    GetChargeTime() const;
virtual std::uint32_t            GetMaxEffectCount() const;
virtual ActorValue               GetAssociatedSkill() const;
virtual bool                     IsTwoHanded() const;
virtual std::uint32_t            GetChunkID() = 0;
virtual void                                   CopyMagicItemData(MagicItem* a_src) = 0;
virtual void                                   LoadMagicItemChunk(TESFile* a_mod, std::uint32_t a_chunkID);
virtual void                                   LoadChunkDataPostProcess(TESFile* a_mod);
virtual const Data*              GetData1() const = 0;
};
struct SpellItemData {
    std::int32_t costOverride;  // 00
    std::uint32_t flags;        // 04
    std::int32_t spellType;     // 08
    float chargeTime;           // 0C
    std::int32_t castingType;   // 10
    std::int32_t delivery;      // 14
    float castDuration;         // 18
};
class SpellItem : public MagicItem { public:
    bool IgnoreLOS() const override; bool GetNoAbsorb() const override; bool GetNoDualCastModifications() const override;
    MagicSystem::Delivery GetDelivery() const override;
    float GetFixedCastDuration() const override;
    bool IgnoresResistance() const override;
    virtual SpellItemData* GetData2();
    std::uint64_t unk08;  // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
    std::uint64_t unk20;  // 20
    std::uint64_t unk28;  // 28
    std::uint64_t unk30;  // 30
    std::uint64_t unk38;  // 38
    std::uint64_t unk40;  // 40
    std::uint64_t unk48;  // 48
    std::uint64_t unk50;  // 50
    std::uint64_t unk58;  // 58
    std::uint64_t unk60;  // 60
    std::uint64_t unk68;  // 68
    std::uint64_t unk70;  // 70
    std::uint64_t unk78;  // 78
    std::uint64_t unk80;  // 80
    std::uint64_t unk88;  // 88
    std::uint64_t unk90;  // 90
    std::uint64_t unk98;  // 98
    std::uint64_t unkA0;  // A0
    std::uint64_t unkA8;  // A8
    std::uint64_t unkB0;  // B0
    std::uint64_t unkB8;  // B8
    SpellItemData data;        // C0
};
