// 0x14b510 EffectSetting::HasKeyword
// Code origin: original reconstruction from local binary analysis; declarations from labelled sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EffectSetting, TESForm, TESFullName, BGSMenuDisplayObject, BGSKeywordForm, BGSKeyword, HasKeyword, formType, data, associatedForm, archetype, fullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// ArchetypeInfo, archetypeInfo, associatedFormType, keywordBase, menuObject, filterValidationFunction, filterValidationItem: GUESS(low); minimal declarations for the observed access paths

#pragma once
#include <cstddef>
class TESForm {
public:
    virtual ~TESForm();
    char unknown08[0x12];
    unsigned char formType;
    char unknown1b[5];
};
class BGSKeyword : public TESForm {};
class TESFullName {
public:
    virtual ~TESFullName();
    const char* fullName;
};
class BGSMenuDisplayObject {
public:
    virtual ~BGSMenuDisplayObject();
    TESForm* menuObject;
};
class BGSKeywordForm {
public:
    virtual ~BGSKeywordForm();
    virtual void InitializeDataComponent();
    virtual void ClearDataComponent();
    virtual void CopyComponent(void*);
    virtual bool HasKeyword(const BGSKeyword* keyword) const;
    char unknown08[0x10];
};
struct ArchetypeInfo {
    int associatedFormType;
    char unknown04[20];
};
extern ArchetypeInfo archetypeInfo[];
class EffectSetting : public TESForm, public TESFullName, public BGSMenuDisplayObject, public BGSKeywordForm {
public:
    bool HasKeyword(const BGSKeyword* keyword) const override;
    void* filterValidationFunction;
    void* filterValidationItem;
    struct {
        char unknown00[8];
        TESForm* associatedForm;
        char unknown10[0x48];
        int archetype;
    } data;
};
static_assert(sizeof(TESForm) == 0x20, "form base size");
static_assert(sizeof(TESFullName) == 0x10, "name base size");
static_assert(sizeof(BGSMenuDisplayObject) == 0x10, "menu base size");
static_assert(sizeof(BGSKeywordForm) == 0x18, "keyword base size");
static_assert(sizeof(ArchetypeInfo) == 24, "archetype row size");
static_assert(offsetof(EffectSetting, data) == 0x68, "effect data offset");
