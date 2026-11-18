// Code origin: names, bases, member offsets and sizes are adapted from the CharmedBaryon/CommonLibSSE-NG
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectARMO, TESObjectARMO::InitializeData, TESObjectARMO::GetDefaultKeyword, TESObjectARMO::Load, TESObjectARMO::SaveGame, TESObjectARMO::LoadGame, TESObjectARMO::InitItemImpl, TESObjectARMO::GetDescriptionOwnerFile, TESObjectARMO::Copy, TESObjectARMO::armorRating, TESObjectARMO::armorAddons, TESObjectARMO::templateArmor, TESObject::~TESObject, TESObject::IsObject, TESObject::GetRefCount, TESObject::Unk_3B, TESObject::IsBoundAnimObject, TESObject::GetWaterType, TESObject::IsAutoCalc, TESObject::SetAutoCalc, TESObject::Clone3D, TESObject::UnClone3D, TESObject::IsMarker, TESObject::IsOcclusionMarker, TESObject::ReplaceModel, TESObject::IncRef, TESObject::DecRef, TESObject::LoadGraphics, TESBoundObject::~TESBoundObject, TESBoundObject::LoadObjectBound, TESBoundObject::IsBoundObject, TESBoundObject::Activate, TESBoundObject::Clone3D, TESBoundObject::ReplaceModel, TESBoundObject::SetObjectVoiceType, TESBoundObject::GetObjectVoiceType, TESBoundObject::GetActivateText, TESBoundObject::CalculateDoFavor, TESBoundObject::HandleRemoveItemFromContainer, TESBoundObject::OnRemove3D, TESBoundObject::OnCheckModels, TESBoundObject::OnCopyReference, TESBoundObject::OnFinishScale, TESBoundObject::boundData, BIPED_MODEL::armorType, BIPED_MODEL::bipedObjectSlots, BGSBipedObjectForm::bipedModelData, TESEnchantableForm::formEnchanting, TESEnchantableForm::amountofEnchantment, TESEnchantableForm::pad14, BGSKeywordForm::GetDefaultKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESObject, TESBoundObject, TESFullName, TESRaceForm, TESEnchantableForm, TESValueForm, TESWeightForm, BGSDestructibleObjectForm, BGSPickupPutdownSounds, TESBipedModelForm, BGSEquipType, BGSBipedObjectForm, BGSBlockBashData, BGSKeywordForm, TESDescription, TESModel, TESModelTextureSwap, TESModelRDT, TESTexture, TESIcon, BGSMessageIcon, BSFixedString, BSTArray, BGSKeyword, TESWaterForm, NiAVObject, BGSVoiceType, BSString, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESValueForm::SaveGame, TESValueForm::LoadGame, ResolveOwnerFile: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class BGSKeyword;
class TESWaterForm;
class NiAVObject;
class BGSVoiceType;
class BSString;
class Actor;
class TESRace;
class EnchantmentItem;
class BGSSoundDescriptorForm;
class BGSEquipSlot;
class BGSImpactDataSet;
class BGSMaterialType;
class TESObjectARMA;

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

// Object bounds: NG's BOUND_DATA is six int16 values (12 bytes) followed by 4 bytes of padding.
struct ObjectBound
{
    std::int16_t boundsMin[3];  // 00
    std::int16_t boundsMax[3];  // 06
};
static_assert(sizeof(ObjectBound) == 0xC, "ObjectBound size");

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

    ObjectBound boundData;  // 20
    std::uint32_t pad2C;  // 2C
};
static_assert(sizeof(TESBoundObject) == 0x30, "TESBoundObject size");

// Component stand-ins. Each carries NG's members and the dtor plus the three component slots.
class BSFixedString
{
public:
    const char* _data;  // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "BSFixedString size");

template <class T>
class BSTArray
{
public:
    T* _data;  // 00
    std::uint32_t _capacity;  // 08
    std::uint32_t pad0C;  // 0C
    std::uint32_t _size;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(BSTArray<TESObjectARMA*>) == 0x18, "BSTArray size");

class TESFullName : public BaseFormComponent
{
public:
    ~TESFullName() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    BSFixedString fullName;  // 08
};
static_assert(sizeof(TESFullName) == 0x10, "TESFullName size");

class TESRaceForm : public BaseFormComponent
{
public:
    ~TESRaceForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    TESRace* race;  // 08
};
static_assert(sizeof(TESRaceForm) == 0x10, "TESRaceForm size");

class TESEnchantableForm : public BaseFormComponent
{
public:
    ~TESEnchantableForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    EnchantmentItem* formEnchanting;  // 08
    std::uint16_t amountofEnchantment;  // 10
    std::uint16_t pad12;  // 12
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(TESEnchantableForm) == 0x18, "TESEnchantableForm size");

class TESValueForm : public BaseFormComponent
{
public:
    ~TESValueForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    // The helpers the armor SaveGame / LoadGame bodies jump to with this component
    // (address 0x1f3660 and address 0x1f36a0); the name and owner are guesses.
    void SaveGame(BGSSaveFormBuffer* a_buf);
    void LoadGame(BGSLoadFormBuffer* a_buf);

    std::int32_t value;  // 08
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(TESValueForm) == 0x10, "TESValueForm size");

class TESWeightForm : public BaseFormComponent
{
public:
    ~TESWeightForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    float weight;  // 08
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(TESWeightForm) == 0x10, "TESWeightForm size");

class BGSDestructibleObjectForm : public BaseFormComponent
{
public:
    ~BGSDestructibleObjectForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    void* data;  // 08, NG: DestructibleObjectData*
};
static_assert(sizeof(BGSDestructibleObjectForm) == 0x10, "BGSDestructibleObjectForm size");

class BGSPickupPutdownSounds : public BaseFormComponent
{
public:
    ~BGSPickupPutdownSounds() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    BGSSoundDescriptorForm* pickupSound;  // 08
    BGSSoundDescriptorForm* putdownSound;  // 10
};
static_assert(sizeof(BGSPickupPutdownSounds) == 0x18, "BGSPickupPutdownSounds size");

class TESModel : public BaseFormComponent
{
public:
    ~TESModel() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual const char* GetModel() const;  // 04
    virtual void SetModel(const char* a_model);  // 05
    virtual void* GetAsModelTextureSwap();  // 06, NG: TESModelTextureSwap*

    BSFixedString model;  // 08
    void* textures;  // 10, NG: BSResource::ID*
    std::uint32_t* addons;  // 18
    std::uint16_t numTextures;  // 20
    std::uint16_t numAddons;  // 22
    std::uint32_t pad24;  // 24
};
static_assert(sizeof(TESModel) == 0x28, "TESModel size");

class TESModelTextureSwap : public TESModel
{
public:
    ~TESModelTextureSwap() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    void* GetAsModelTextureSwap() override;  // 06

    void* alternateTextures;  // 28, NG: AlternateTexture*
    std::uint32_t numAlternateTextures;  // 30
    std::uint32_t pad34;  // 34
};
static_assert(sizeof(TESModelTextureSwap) == 0x38, "TESModelTextureSwap size");

class TESModelRDT : public TESModel
{
public:
    ~TESModelRDT() override;  // 00
};
static_assert(sizeof(TESModelRDT) == 0x28, "TESModelRDT size");

class TESTexture : public BaseFormComponent
{
public:
    ~TESTexture() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual std::uint32_t GetMaxAllowedSize();  // 04
    virtual const char* GetAsNormalFile(BSString& a_out) const;  // 05
    virtual const char* GetDefaultPath() const;  // 06

    BSFixedString textureName;  // 08
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");

class TESIcon : public TESTexture
{
public:
    ~TESIcon() override;  // 00
};
static_assert(sizeof(TESIcon) == 0x10, "TESIcon size");

class BGSMessageIcon : public BaseFormComponent
{
public:
    ~BGSMessageIcon() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    TESIcon icon;  // 08
};
static_assert(sizeof(BGSMessageIcon) == 0x18, "BGSMessageIcon size");

class TESBipedModelForm : public BaseFormComponent
{
public:
    ~TESBipedModelForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    TESModelTextureSwap worldModels[2];  // 08 (male, female)
    TESIcon inventoryIcons[2];  // 78
    BGSMessageIcon messageIcons[2];  // 98
    TESModelRDT constraintTemplate;  // C8
};
static_assert(sizeof(TESBipedModelForm) == 0xF0, "TESBipedModelForm size");

class BGSEquipType : public BaseFormComponent
{
public:
    ~BGSEquipType() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual void SetEquipSlot(BGSEquipSlot* a_slot);  // 04

    BGSEquipSlot* equipSlot;  // 08
};
static_assert(sizeof(BGSEquipType) == 0x10, "BGSEquipType size");

// BIPED_MODEL (BOD2): slot mask then armor type.
struct BIPED_MODEL
{
    enum class ArmorType : std::uint32_t
    {
        kLightArmor = 0,
        kHeavyArmor = 1,
        kClothing = 2
    };

    std::uint32_t bipedObjectSlots;  // 0
    ArmorType armorType;  // 4
};
static_assert(sizeof(BIPED_MODEL) == 0x8, "BIPED_MODEL size");

class BGSBipedObjectForm : public BaseFormComponent
{
public:
    ~BGSBipedObjectForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    BIPED_MODEL bipedModelData;  // 08
};
static_assert(sizeof(BGSBipedObjectForm) == 0x10, "BGSBipedObjectForm size");

class BGSBlockBashData : public BaseFormComponent
{
public:
    ~BGSBlockBashData() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    BGSImpactDataSet* blockBashImpactDataSet;  // 08
    BGSMaterialType* altBlockMaterialType;  // 10
};
static_assert(sizeof(BGSBlockBashData) == 0x18, "BGSBlockBashData size");

class BGSKeywordForm : public BaseFormComponent
{
public:
    ~BGSKeywordForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual BGSKeyword* GetDefaultKeyword() const;  // 04

    BGSKeyword** keywords;  // 08
    std::uint32_t numKeywords;  // 10
    std::uint32_t pad14;  // 14
};
static_assert(sizeof(BGSKeywordForm) == 0x18, "BGSKeywordForm size");

class TESDescription : public BaseFormComponent
{
public:
    ~TESDescription() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    std::uint32_t fileOffset;  // 08
    std::uint32_t descriptionText;  // 0C, NG: BGSLocalizedStringDL
};
static_assert(sizeof(TESDescription) == 0x10, "TESDescription size");

class TESObjectARMO :
    public TESBoundObject,             // 000
    public TESFullName,                // 030
    public TESRaceForm,                // 040
    public TESEnchantableForm,         // 050
    public TESValueForm,               // 068
    public TESWeightForm,              // 078
    public BGSDestructibleObjectForm,  // 088
    public BGSPickupPutdownSounds,     // 098
    public TESBipedModelForm,          // 0B0
    public BGSEquipType,               // 1A0
    public BGSBipedObjectForm,         // 1B0
    public BGSBlockBashData,           // 1C0
    public BGSKeywordForm,             // 1D8
    public TESDescription              // 1F0
{
public:
    TESObjectARMO();

    void InitializeData() override;  // 04, compared: 0x27dae0
    bool Load(TESFile* a_mod) override;  // 06
    void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E, compared: 0x27ee20
    void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F, compared: 0x27ee60
    void InitItemImpl() override;  // 13
    TESFile* GetDescriptionOwnerFile() const override;  // 14, compared: 0x27f1b0
    void Copy(TESForm* a_srcForm) override;  // 2F
    BGSKeyword* GetDefaultKeyword() const override;  // BGSKeywordForm slot 04
    int GetSkill() const;  // slot declared only, not compared

    std::uint32_t armorRating;  // 200
    std::uint32_t pad204;  // 204
    BSTArray<TESObjectARMA*> armorAddons;  // 208
    TESObjectARMO* templateArmor;  // 220
};
static_assert(sizeof(TESObjectARMO) == 0x228, "TESObjectARMO size");
static_assert(offsetof(TESObjectARMO, bipedModelData) == 0x1B8, "bipedModelData offset");
static_assert(offsetof(TESObjectARMO, amountofEnchantment) == 0x60, "amountofEnchantment offset");
static_assert(offsetof(TESObjectARMO, armorRating) == 0x200, "armorRating offset");
static_assert(offsetof(TESObjectARMO, templateArmor) == 0x220, "templateArmor offset");
