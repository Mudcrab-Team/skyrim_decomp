// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm, TESForm::~TESForm, TESForm::InitializeDataComponent, TESForm::ClearDataComponent, TESForm::CopyComponent, TESForm::InitializeData, TESForm::ClearData, TESForm::Load, TESForm::LoadPartial, TESForm::LoadEdit, TESForm::CreateDuplicateForm, TESForm::AddChange, TESForm::RemoveChange, TESForm::FindInFileFast, TESForm::CheckSaveGame, TESForm::SaveGame, TESForm::LoadGame, TESForm::InitLoadGame, TESForm::FinishLoadGame, TESForm::Revert, TESForm::InitItemImpl, TESForm::GetDescriptionOwnerFile, TESForm::GetSavedFormType, TESForm::GetFormDetailedString, TESForm::GetKnown, TESForm::GetRandomAnim, TESForm::GetPlayable, TESForm::IsHeadingMarker, TESForm::GetDangerous, TESForm::QHasCurrents, TESForm::GetObstacle, TESForm::QIsLODLandObject, TESForm::GetOnLocalMap, TESForm::GetMustUpdate, TESForm::SetOnLocalMap, TESForm::GetIgnoredBySandbox, TESForm::SetDelete, TESForm::SetAltered, TESForm::SaveObjectBound, TESForm::LoadObjectBound, TESForm::IsBoundObject, TESForm::IsObject, TESForm::IsMagicItem, TESForm::IsWater, TESForm::AsReference1, TESForm::AsReference2, TESForm::GetRefCount, TESForm::GetTextForParsedSubTag, TESForm::Copy, TESForm::BelongsInGroup, TESForm::CreateGroupData, TESForm::GetFormEditorID, TESForm::SetFormEditorID, TESForm::IsParentForm, TESForm::IsParentFormTree, TESForm::IsFormTypeChild, TESForm::Activate, TESForm::SetFormID, TESForm::GetObjectTypeName, TESForm::QAvailableInGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFile, BGSSaveFormBuffer, BGSLoadFormBuffer, TESObjectREFR, BSFixedString, FORM_GROUP, TESBoundObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FORM, FORM::form, FORM::length, FORM::flags, FORM::formID, FORM::versionControl, FORM::formVersion, FORM::vcVersion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::sourceFiles, TESForm::formFlags, TESForm::formID, TESForm::inGameFormFlags, TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets 08, 10, 14, 18, 1A
// FORM_ENUM_STRING, FORM_ENUM_STRING::formString, FORM_ENUM_STRING::formCode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG puts the type id at 00 and the code at 10, the image reads a four-character code at 00
// formEnumString, FORM_ENUM_STRING::unk10: GUESS(low)
// unknown08, unknown1b, unknown1c: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/BaseFormComponent.h"

class TESFile;
class BGSSaveFormBuffer;
class BGSLoadFormBuffer;
class TESObjectREFR;
class BSFixedString;
struct FORM_GROUP;
class TESBoundObject;

enum class FormType : int;
using FormID = std::uint32_t;

struct FORM
{
    std::uint32_t form;            // 00
    std::uint32_t length;          // 04
    std::uint32_t flags;           // 08
    FormID formID;                 // 0C
    std::uint32_t versionControl;  // 10
    std::uint16_t formVersion;     // 14
    std::uint16_t vcVersion;       // 16
};
static_assert(sizeof(FORM) == 0x18, "FORM size");

struct FORM_ENUM_STRING
{
    std::uint32_t formCode;  // 00
    const char* formString;  // 08
    std::uint32_t unk10;     // 10
};
static_assert(sizeof(FORM_ENUM_STRING) == 0x18, "FORM_ENUM_STRING size");
extern FORM_ENUM_STRING formEnumString[];

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

    std::uint8_t unknown08[0x0c];   // 08 sourceFiles, formFlags
    FormID formID;                  // 14
    std::uint16_t inGameFormFlags;  // 18
    std::uint8_t formType;          // 1A
    std::uint8_t unknown1b;         // 1B
    std::uint32_t unknown1c;        // 1C
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");
