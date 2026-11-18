// Source exposure: mixed (community headers and pinned-image analysis).
// Origin: community declarations and target analysis.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESSoulGem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include <cstddef>
// Type declarations for the TESForm unit (build sse-steam-1-7-104).
//
// Labels: v2
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Names and member offsets follow CharmedBaryon/CommonLibSSE-NG
// b93280e832f263dbef44e44cbe2936622a02f91a (MIT) and meh321/AddressLibraryDatabase 0379cb6
// (used with the author's permission as reported by the maintainer).
// Adapted bodies: none declared; tools/check_origin.py reports none above its threshold (0.75)
// at CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8.
// TESForm::ClearData's empty body necessarily coincides with the FNV decompilation's.
// Every class other than TESForm and
// BaseFormComponent is a minimal stand-in that declares only the members and virtual slots the
// compared code needs; the layouts of the stand-ins are not claimed to match the game.
// BaseFormComponent, TESForm, TESForm::ClearData, ::SaveGame, ::LoadGame, ::CopyComponent, ::GetGoldValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::InitializeData, ::AsReference2, ::SetAltered: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the other slot names 04 to 3A follow the NG header too and only the slot order matters here
// TESForm::sourceFiles, ::formFlags, ::formID, ::inGameFormFlags, ::formType, ::pad1B, ::pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::RecordFlags, ::ChangeFlags, kAltered, kPersistent, kTemporary, kFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::InGameFormFlag: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::IsPersistent, ::IsTemporaryFormID, ::GetEnchantment: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); NG declares IsPersistent only on TESObjectREFR
// TESForm::GetGoldValue: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); id 14978 names this address; NG declares the name but implements it itself
// TESFileContainer, TESFileArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the array layout (data, size) is read from the listings
// TESFile: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESDataHandler, TESDataHandler::IsTemporaryFormID: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESDataHandler::singleton: GUESS(low); the global pointer at RVA 0x219ded8, which NG reads through GetSingleton
// ExtraDataList, ExtraDataList::GetEnchantment: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// EnchantmentItem, TESEnchantableForm, TESEnchantableForm::formEnchanting, TESValueForm, TESValueForm::value, MagicItem, MagicItem::CalculateCost, AlchemyItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESEnchantableForm, TESValueForm, MagicItem, AlchemyItem:; the names of the type descriptors the casts use, read from the image RTTI
// BGSSaveGameBuffer, BGSSaveFormBuffer, BGSSaveGameBuffer::SaveDataEndian, BGSSaveFormBuffer::unk18: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; SaveDataEndian takes more parameters than NG declares
// BGSSaveFormBuffer::unk1B: GUESS(low); a byte at offset 0x1B whose bit 0 SaveGame tests; NG declares the region only as unk18
// BGSLoadGameBuffer, BGSLoadFormBuffer, BGSLoadGameBuffer::LoadDataEndian, BGSLoadFormData::changeFlags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

enum class FormType : std::uint8_t {
    None = 0
};

using FormID = std::uint32_t;

class BSFixedString;
class TESObjectREFR;
class TESBoundObject;
class FORM;
class FORM_GROUP;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class EnchantmentItem;

class BaseFormComponent {
public:
    virtual ~BaseFormComponent();                            // 00
    virtual void InitializeDataComponent() = 0;              // 01
    virtual void ClearDataComponent() = 0;                   // 02
    virtual void CopyComponent(BaseFormComponent* a_rhs);    // 03
};


class Actor;
class TESFile;

struct TESFileArray {
    TESFile**     data;  // 00
    std::uint32_t size;  // 08
};

class TESFileContainer {
public:
    TESFileArray* array;  // 0
};

class ExtraDataList {
public:
    EnchantmentItem* GetEnchantment();
};

class TESForm : public BaseFormComponent {
public:
    struct ChangeFlags {
        enum ChangeFlag : std::uint32_t {
            kCreated = 0,
            kFlags   = 1 << 0
        };
    };

    struct RecordFlags {
        enum RecordFlag : std::uint32_t {
            kAltered    = 1 << 1,
            kPersistent = 1 << 10,
            kTemporary  = 1 << 14
        };
    };

    enum class InGameFormFlag : std::uint16_t {
        kNone = 0
    };

    ~TESForm() override;                                    // 00
    void InitializeDataComponent() override;                // 01
    void ClearDataComponent() override;                     // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    virtual void                       InitializeData();                                       // 04
    virtual void                       ClearData();                                            // 05
    virtual bool                       Load(TESFile* a_mod);                                   // 06
    virtual bool                       LoadPartial(TESFile* a_mod);                            // 07
    virtual bool                       LoadEdit(TESFile* a_mod);                               // 08
    virtual TESForm*                   CreateDuplicateForm(bool a_createEditorID, void* a_arg2);  // 09
    virtual bool                       AddChange(std::uint32_t a_changeFlags);                 // 0A
    virtual void                       RemoveChange(std::uint32_t a_changeFlags);              // 0B
    virtual bool                       FindInFileFast(TESFile* a_mod);                         // 0C
    virtual bool                       CheckSaveGame(BGSSaveFormBuffer* a_buf);                // 0D
    virtual void                       SaveGame(BGSSaveFormBuffer* a_buf);                     // 0E
    virtual void                       LoadGame(BGSLoadFormBuffer* a_buf);                     // 0F
    virtual void                       InitLoadGame(BGSLoadFormBuffer* a_buf);                 // 10
    virtual void                       FinishLoadGame(BGSLoadFormBuffer* a_buf);               // 11
    virtual void                       Revert(BGSLoadFormBuffer* a_buf);                       // 12
    virtual void                       InitItemImpl();                                         // 13
    virtual TESFile*                   GetDescriptionOwnerFile() const;                        // 14
    virtual FormType                   GetSavedFormType() const;                               // 15
    virtual void                       GetFormDetailedString(char* a_buf, std::uint32_t a_bufLen);  // 16
    virtual bool                       GetKnown() const;                                       // 17
    virtual bool                       GetRandomAnim() const;                                  // 18
    virtual bool                       GetPlayable() const;                                    // 19
    virtual bool                       IsHeadingMarker() const;                                // 1A
    virtual bool                       GetDangerous() const;                                   // 1B
    virtual bool                       QHasCurrents() const;                                   // 1C
    virtual bool                       GetObstacle() const;                                    // 1D
    virtual bool                       QIsLODLandObject() const;                               // 1E
    virtual bool                       GetOnLocalMap() const;                                  // 1F
    virtual bool                       GetMustUpdate() const;                                  // 20
    virtual void                       SetOnLocalMap(bool a_set);                              // 21
    virtual bool                       GetIgnoredBySandbox() const;                            // 22
    virtual void                       SetDelete(bool a_set);                                  // 23
    virtual void                       SetAltered(bool a_set);                                 // 24
    virtual void                       SaveObjectBound();                                      // 25
    virtual void                       LoadObjectBound(TESFile* a_mod);                        // 26
    virtual bool                       IsBoundObject() const;                                  // 27
    virtual bool                       IsObject() const;                                       // 28
    virtual bool                       IsMagicItem() const;                                    // 29
    virtual bool                       IsWater() const;                                        // 2A
    virtual TESObjectREFR*             AsReference1();                                         // 2B
    virtual const TESObjectREFR*       AsReference2() const;                                   // 2C
    virtual std::uint32_t              GetRefCount() const;                                    // 2D
    virtual const char*                GetTextForParsedSubTag(const BSFixedString& a_tag) const;  // 2E
    virtual void                       Copy(TESForm* a_srcForm);                               // 2F
    virtual bool                       BelongsInGroup(FORM* a_form, bool a_allowParentGroups, bool a_currentOnly);  // 30
    virtual void                       CreateGroupData(FORM* a_form, FORM_GROUP* a_group);     // 31
    virtual const char*                GetFormEditorID() const;                                // 32
    virtual bool                       SetFormEditorID(const char* a_str);                     // 33
    virtual bool                       IsParentForm();                                         // 34
    virtual bool                       IsParentFormTree();                                     // 35
    virtual bool                       IsFormTypeChild(FormType a_type);                       // 36
    virtual bool                       Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount);  // 37
    virtual void                       SetFormID(FormID a_id, bool a_updateFile);              // 38
    virtual const char*                GetObjectTypeName() const;                              // 39
    virtual bool                       QAvailableInGame() const;                               // 3A

    std::int32_t     GetGoldValue() const;
    EnchantmentItem* GetEnchantment(ExtraDataList* a_extraList);
    bool             IsPersistent() const;
    bool             IsTemporaryFormID() const;

    // members
    TESFileContainer sourceFiles;      // 08
    std::uint32_t    formFlags;        // 10
    FormID           formID;           // 14
    std::uint16_t    inGameFormFlags;  // 18
    FormType         formType;         // 1A
    std::uint8_t     pad1B;            // 1B
    std::uint32_t    pad1C;            // 1C
};
static_assert(sizeof(TESForm) == 0x20, "layout");



class MagicItem : public TESForm {
public:
    float CalculateCost(Actor* a_caster) const;
};

class AlchemyItem : public MagicItem {
};

class BGSSaveGameBuffer {
public:
    virtual ~BGSSaveGameBuffer();  // 00

    void SaveDataEndian(const void* a_data, std::uint32_t a_size, std::uint32_t a_count, std::uint32_t a_arg4);

    void*         buffer;          // 08
    std::uint32_t size;            // 10
    std::uint32_t bufferPosition;  // 14
};

class BGSSaveFormBuffer : public BGSSaveGameBuffer {
public:
    std::uint8_t  unk18[3];  // 18
    std::uint8_t  unk1B;     // 1B, bit 0 tested by SaveGame (seen in the listing)
    std::uint32_t unk1C;     // 1C
    std::uint64_t unk20;  // 20
    TESForm*      form;   // 28
};

class BGSLoadGameBuffer {
public:
    virtual ~BGSLoadGameBuffer();  // 00

    void LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);

    void*         buffer;          // 08
    std::uint64_t unk10;           // 10
    std::uint32_t unk18;           // 18
    std::uint32_t unk1C;           // 1C
    std::uint32_t unk20;           // 20
    std::uint32_t bufferPosition;  // 24
};

class BGSLoadFormBuffer : public BGSLoadGameBuffer {
public:
    FormID        formID;            // 28
    std::uint32_t size;              // 2C
    std::uint32_t uncompressedSize;  // 30
    std::uint32_t pad34;             // 34
    TESForm*      form;              // 38
    std::uint32_t changeFlags;       // 40
    std::uint32_t oldChangeFlags;    // 44
};

class TESDataHandler {
public:
    bool IsTemporaryFormID(FormID a_formID);

    static TESDataHandler* singleton;
};

inline BaseFormComponent::~BaseFormComponent() {}
class BSFixedString { public: BSFixedString(); ~BSFixedString(); const char* value; };
class TESFullName : public BaseFormComponent { public: ~TESFullName() override {} void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual std::uint32_t GetFullNameLength() const; virtual const char* GetFullName() const; BSFixedString fullName; };
class TESModel : public BaseFormComponent { public: ~TESModel() override; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual const char* GetModel() const; virtual void SetModel(const char*); virtual void* GetAsModelTextureSwap(); BSFixedString model; void* textures; std::uint32_t* addons; std::uint16_t numTextures,numAddons; };
class TESTexture : public BaseFormComponent { public: virtual ~TESTexture(); void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual std::uint32_t GetMaxAllowedSize(); virtual void GetAsNormalFile(); virtual void GetDefaultPath(); BSFixedString textureName; };
class TESIcon : public TESTexture { public: ~TESIcon() override; };
class TESObject : public TESForm {};
class TESBoundObject : public TESObject { public: virtual ~TESBoundObject(); std::int16_t boundMin[3],boundMax[3]; };
class TESModelTextureSwap : public TESModel { public: ~TESModelTextureSwap() override; void CopyComponent(BaseFormComponent*) override; void* alternateTextures; std::uint32_t numAlternateTextures; };
class TESModelRDT : public TESModel { public: ~TESModelRDT() override; };
class BGSDestructibleObjectForm : public BaseFormComponent { public: ~BGSDestructibleObjectForm() override ; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; void* data; };
class TESValueForm : public BaseFormComponent { public: ~TESValueForm() override ; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; std::int32_t value; };
class TESWeightForm : public BaseFormComponent { public: ~TESWeightForm() override ; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; float weight; };
class BGSMessageIcon : public BaseFormComponent { public: ~BGSMessageIcon() override ; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; TESIcon icon; };
class BGSPickupPutdownSounds : public BaseFormComponent { public: ~BGSPickupPutdownSounds() override ; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; void* pickupSound; void* putdownSound; };
class BGSKeywordForm : public BaseFormComponent { public: ~BGSKeywordForm() override ; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; void** keywords; std::uint32_t numKeywords; };
class TESObjectMISC : public TESBoundObject, public TESFullName, public TESModelTextureSwap, public TESIcon, public TESValueForm, public TESWeightForm, public BGSDestructibleObjectForm, public BGSMessageIcon, public BGSPickupPutdownSounds, public BGSKeywordForm { public: ~TESObjectMISC() override; void InitializeData() override; }; static_assert(sizeof(TESObjectMISC)==0x100,"misc object size");
class TESSoulGem : public TESObjectMISC { public: TESSoulGem(); ~TESSoulGem() override; void InitializeData() override; virtual void InitImpl(); virtual void LoadImpl(TESFile*,std::uint32_t); TESSoulGem* linkedSoulGem; std::uint8_t currentSoul,soulCapacity; std::uint16_t unknown10A; std::uint32_t unknown10C; }; static_assert(sizeof(TESSoulGem)==0x110,"soul gem size");
void* SoulSourceFile(TESForm*,std::int32_t); void ResolveSoulID(std::uint32_t*,void*); TESForm* LookupSoulID(std::uint32_t);
std::uint32_t SoulFileType(TESFile*); void ReadSoulFile(TESFile*,void*,std::uint32_t); std::uint32_t SoulFileChunkSize(TESFile*); bool SoulFileBigEndian(TESFile*);


// TESFile: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); represented prefix only, no allocation-size claim.
struct SoulFileForm { std::uint32_t form,length,flags,formID,versionControl; std::uint16_t formVersion,vcVersion; };
class TESFile { public: std::uint32_t GetFormType(); void ReadData(void*,std::uint32_t); std::uint32_t lastError; TESFile* threadSafeParent; void* threadSafeFileMap; std::uint64_t unknown018,unknown020; std::uint8_t unknown028,unknown029; void* lockedFile; void* file; void* formUserDataBitArray; void* formVersionBitArray; void* formIDBitArray; char fileName[260]; char path[260]; char* buffer; std::uint32_t bufferAllocSize,firstCellOffset,currCellOffset,unknown274; void* currCell; std::uint32_t currRefOffset; SoulFileForm currentform; std::uint32_t currentChunkID,actualChunkSize,fileSize,fileOffset,formOffset,chunkOffset; SoulFileForm saveform; std::uint32_t saveFormOffset; std::uint64_t saveChunkOffset,unknown2D8,unknown2E0; std::uint8_t unknown2E8; bool isBigEndian; };
static_assert(offsetof(TESFile,actualChunkSize)==0x2A0,"file chunk-size member"); static_assert(offsetof(TESFile,isBigEndian)==0x2E9,"file byte order member");
