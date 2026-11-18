// Code origin: names, bases, virtual slots and member offsets from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); the bodies are written from the listing of the pinned image
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESFlora, TESFlora::Activate, ::InitItemImpl, ::~TESFlora, ::Load, ::GetActivateText, ::CalculateDoFavor, TESObjectACTI and its virtual overrides and members (soundLoop, soundActivate, waterForm, flags), TESBoundAnimObject, TESBoundObject, TESBoundObject::boundData, TESObject, TESForm and its virtual functions and members (sourceFiles, formFlags, formID, inGameFormFlags, formType), TESForm::IsInitialized (name only, the body tests record flag bit 3 as written here): COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESProduceForm, TESProduceForm::harvestSound, ::produceItem, ::produceChance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG derives TESFlora from TESProduceForm at C8, here it is a member at C8 so that its address is the subobject address
// TESFullName, TESModel, TESModelTextureSwap, BGSDestructibleObjectForm, BGSOpenCloseForm, BGSKeywordForm and their members: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); secondary bases of TESObjectACTI flattened into members at their NG offsets
// TESFlora::produceForm: STANDIN GUESS(low); NG's base subobject at C8
// TESProduceForm::Activate (address 0x1ee5b0, only the first two parameters are written): STANDIN GUESS(low)
// TESProduceForm::CopyFromForm (address 0x1ee500, takes the owning form): STANDIN GUESS(low)
// TESObjectACTI::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); address 0x279d20, called by qualified name
// TESForm::SetFormFlag: GUESS(low); non-virtual helper at address 0x1e60b0 taking a bool, named the same in other units
// BSFixedString, BSString, TESFileArray, TESFile, TESObjectREFR, Actor, TESWaterForm, NiAVObject, BGSVoiceType, BGSSoundDescriptorForm, BGSKeyword: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations or a pointer-sized reduction
#pragma once

#include <cstdint>
#include <cstddef>

class BGSLoadFormBuffer;
class BGSSaveFormBuffer;
struct FORM;
struct FORM_GROUP;
class TESFile;
class TESObjectREFR;
class BSString;
class Actor;
class TESWaterForm;
class NiAVObject;
class BGSVoiceType;
class BGSSoundDescriptorForm;
class BGSKeyword;
class TESFileArray;
class TESBoundObject;
class TESForm;
enum class FormType : std::uint8_t;
using FormID = std::uint32_t;

class BSFixedString
{
public:
    const char* _data;  // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "BSFixedString size");

class BaseFormComponent
{
public:
    virtual ~BaseFormComponent();  // 00
    virtual void InitializeDataComponent();  // 01
    virtual void ClearDataComponent();  // 02
    virtual void CopyComponent(BaseFormComponent* a_rhs);  // 03
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

class TESFullName : public BaseFormComponent
{
public:
    BSFixedString fullName;  // 08 - FULL
};

class TESModel : public BaseFormComponent
{
public:
    BSFixedString  model;        // 08 - MODL
    void*          textures;     // 10 - MODT
    std::uint32_t* addons;       // 18
    std::uint16_t  numTextures;  // 20
    std::uint16_t  numAddons;    // 22
    std::uint32_t  pad24;        // 24
};

class TESModelTextureSwap : public TESModel
{
public:
    void*         alternateTextures;     // 28 - MODS
    std::uint32_t numAlternateTextures;  // 30
    std::uint32_t pad34;                 // 34
};
static_assert(sizeof(TESModelTextureSwap) == 0x38, "TESModelTextureSwap size");

struct DestructibleObjectData;

class BGSDestructibleObjectForm : public BaseFormComponent
{
public:
    DestructibleObjectData* data;  // 08
};

class BGSOpenCloseForm : public BaseFormComponent
{
};

class BGSKeywordForm : public BaseFormComponent
{
public:
    BGSKeyword**  keywords;     // 08 - KWDA
    std::uint32_t numKeywords;  // 10 - KSIZ
    std::uint32_t pad14;        // 14
};
static_assert(sizeof(BGSKeywordForm) == 0x18, "BGSKeywordForm size");

class TESProduceForm : public BaseFormComponent
{
public:
    bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef);  // address 0x1ee5b0
    void CopyFromForm(TESForm* a_owner);                                      // address 0x1ee500

    BGSSoundDescriptorForm* harvestSound;      // 08 - SNAM
    void*                   produceItem;       // 10 - PFIG
    std::int8_t             produceChance[4];  // 18 - PFPC, one per season
    std::uint32_t           pad1C;             // 1C
};
static_assert(sizeof(TESProduceForm) == 0x20, "TESProduceForm size");

class TESForm : public BaseFormComponent
{
public:
    ~TESForm() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual void InitializeData();  // 04
    virtual void ClearData();  // 05
    virtual bool Load(TESFile* a_mod);  // 06
    virtual bool LoadPartial(TESFile* a_mod);  // 07
    virtual bool LoadEdit(TESFile* a_mod);  // 08
    virtual TESForm* CreateDuplicateForm(bool a_createEditorID, void* a_arg2);  // 09
    virtual bool AddChange(std::uint32_t a_changeFlags);  // 0A
    virtual void RemoveChange(std::uint32_t a_changeFlags);  // 0B
    virtual bool FindInFileFast(TESFile* a_mod);  // 0C
    virtual bool CheckSaveGame(BGSSaveFormBuffer* a_buf);  // 0D
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // 0E
    virtual void LoadGame(BGSLoadFormBuffer* a_buf);  // 0F
    virtual void InitLoadGame(BGSLoadFormBuffer* a_buf);  // 10
    virtual void FinishLoadGame(BGSLoadFormBuffer* a_buf);  // 11
    virtual void Revert(BGSLoadFormBuffer* a_buf);  // 12
    virtual void InitItemImpl();  // 13
    virtual TESFile* GetDescriptionOwnerFile() const;  // 14
    virtual FormType GetSavedFormType() const;  // 15
    virtual void GetFormDetailedString(char* a_buf, std::uint32_t a_bufLen);  // 16
    virtual bool GetKnown() const;  // 17
    virtual bool GetRandomAnim() const;  // 18
    virtual bool GetPlayable() const;  // 19
    virtual bool IsHeadingMarker() const;  // 1A
    virtual bool GetDangerous() const;  // 1B
    virtual bool QHasCurrents() const;  // 1C
    virtual bool GetObstacle() const;  // 1D
    virtual bool QIsLODLandObject() const;  // 1E
    virtual bool GetOnLocalMap() const;  // 1F
    virtual bool GetMustUpdate() const;  // 20
    virtual void SetOnLocalMap(bool a_set);  // 21
    virtual bool GetIgnoredBySandbox() const;  // 22
    virtual void SetDelete(bool a_set);  // 23
    virtual void SetAltered(bool a_set);  // 24
    virtual void SaveObjectBound();  // 25
    virtual void LoadObjectBound(TESFile* a_mod);  // 26
    virtual bool IsBoundObject() const;  // 27
    virtual bool IsObject() const;  // 28
    virtual bool IsMagicItem() const;  // 29
    virtual bool IsWater() const;  // 2A
    virtual TESObjectREFR* AsReference1();  // 2B
    virtual const TESObjectREFR* AsReference2() const;  // 2C
    virtual std::uint32_t GetRefCount() const;  // 2D
    virtual const char* GetTextForParsedSubTag(const BSFixedString& a_tag) const;  // 2E
    virtual void Copy(TESForm* a_srcForm);  // 2F
    virtual bool BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly);  // 30
    virtual void CreateGroupData(FORM* a_form, FORM_GROUP* a_group);  // 31
    virtual const char* GetFormEditorID() const;  // 32
    virtual bool SetFormEditorID(const char* a_str);  // 33
    virtual bool IsParentForm();  // 34
    virtual bool IsParentFormTree();  // 35
    virtual bool IsFormTypeChild(FormType a_type);  // 36
    virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount);  // 37
    virtual void SetFormID(FormID a_id, bool a_updateFile);  // 38
    virtual const char* GetObjectTypeName() const;  // 39
    virtual bool QAvailableInGame() const;  // 3A


    bool IsInitialized() const { return (formFlags >> 3) & 1; }  // record flag bit 3
    void SetFormFlag(bool a_set);  // address 0x1e60b0

    TESFileArray* sourceFiles;      // 08
    std::uint32_t formFlags;        // 10
    FormID        formID;           // 14
    std::uint16_t inGameFormFlags;  // 18
    std::uint8_t  formType;         // 1A
    std::uint8_t  pad1B;            // 1B
    std::uint32_t pad1C;            // 1C
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");
static_assert(offsetof(TESForm, formFlags) == 0x10, "TESForm::formFlags offset");

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
    std::uint8_t  boundMin[6];  // 20 - OBND min
    std::uint8_t  boundMax[6];  // 26 - OBND max
    std::uint32_t pad2C;        // 2C
};
static_assert(sizeof(TESBoundObject) == 0x30, "TESBoundObject size");

class TESBoundAnimObject : public TESBoundObject
{
public:
    ~TESBoundAnimObject() override;  // 00
    bool IsBoundAnimObject() override;  // 3C
    bool ReplaceModel(const char* a_str) override;  // 4B
};
static_assert(sizeof(TESBoundAnimObject) == 0x30, "TESBoundAnimObject size");

class TESObjectACTI : public TESBoundAnimObject
{
public:
    ~TESObjectACTI() override;  // 00
    void InitializeData() override;  // 04
    void ClearData() override;  // 05
    bool Load(TESFile* a_mod) override;  // 06
    void SaveGame(BGSSaveFormBuffer* a_buf) override;  // 0E
    void LoadGame(BGSLoadFormBuffer* a_buf) override;  // 0F
    void InitItemImpl() override;  // 13
    bool GetIgnoredBySandbox() const override;  // 22
    bool IsWater() const override;  // 2A
    bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37
    TESWaterForm* GetWaterType() const override;  // 3D
    bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;  // 4C
    bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;  // 4D
    TESFullName               fullName;          // 30
    TESModelTextureSwap       modelTextureSwap;  // 40
    BGSDestructibleObjectForm destructible;      // 78
    BGSOpenCloseForm          openClose;         // 88
    BGSKeywordForm            keywordForm;       // 90
    BGSSoundDescriptorForm*   soundLoop;         // A8 - SNAM
    BGSSoundDescriptorForm*   soundActivate;     // B0 - VNAM
    TESWaterForm*             waterForm;         // B8 - WNAM
    std::uint16_t             flags;             // C0 - FNAM
    std::uint16_t             padC2;             // C2
    std::uint32_t             padC4;             // C4
};
static_assert(sizeof(TESObjectACTI) == 0xC8, "TESObjectACTI size");

class TESFlora : public TESObjectACTI
{
public:
    ~TESFlora() override;  // 00
    bool Load(TESFile* a_mod) override;  // 06
    void InitItemImpl() override;  // 13 - compared: 0x26da40
    bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount) override;  // 37 - compared: 0x26da90
    bool GetActivateText(TESObjectREFR* a_activator, BSString& a_dst) override;  // 4C
    bool CalculateDoFavor(Actor* a_activator, bool a_arg2, TESObjectREFR* a_toActivate, float a_arg3) override;  // 4D

    TESProduceForm produceForm;  // C8 - NG's second base
};
static_assert(sizeof(TESFlora) == 0xE8, "TESFlora size");
static_assert(offsetof(TESFlora, produceForm) == 0xC8, "TESFlora::produceForm offset");
