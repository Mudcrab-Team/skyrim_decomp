// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x2e4ac0 (skyrim_shared/forms/TESForm): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// at CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8.
// ::SaveGame, ::LoadGame, ::CopyComponent, ::GetGoldValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ::AsReference2, ::SetAltered: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the other slot names 04 to 3A follow the NG header too and only the slot order matters here
// ::formFlags, ::formID, ::inGameFormFlags, ::formType, ::pad1B, ::pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ::ChangeFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ::IsTemporaryFormID, ::GetEnchantment: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); NG declares IsPersistent only on TESObjectREFR
// TESFileContainer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the array layout (data, size) is read from the listings
// TESFile: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESDataHandler::IsTemporaryFormID: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// ExtraDataList, ExtraDataList::GetEnchantment: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// EnchantmentItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSaveFormBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; SaveDataEndian takes more parameters than NG declares
// BGSLoadFormBuffer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function2e4ad0, Owner2e4ad0: GUESS(low) STANDIN
// BaseFormComponent, kAltered, kPersistent, kTemporary, kFlags: GUESS(low) STANDIN
#pragma once
#include "TESForm.h"
#include <typeinfo>

class Owner2e4ad0 : public BaseFormComponent {
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

    ~Owner2e4ad0() override;                                    // 00
    void InitializeDataComponent() override;                // 01
    void ClearDataComponent() override;                     // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

    virtual void                       InitializeData();                                       // 04
    virtual void                       ClearData();                                            // 05
    virtual bool                       Load(TESFile* a_mod);                                   // 06
    virtual bool                       LoadPartial(TESFile* a_mod);                            // 07
    virtual bool                       LoadEdit(TESFile* a_mod);                               // 08
    virtual Owner2e4ad0*                   CreateDuplicateForm(bool a_createEditorID, void* a_arg2);  // 09
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
    virtual void                       Copy(Owner2e4ad0* a_srcForm);                               // 2F
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
    bool             Function2e4ad0() const;
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
static_assert(sizeof(Owner2e4ad0) == 0x20, "layout");
