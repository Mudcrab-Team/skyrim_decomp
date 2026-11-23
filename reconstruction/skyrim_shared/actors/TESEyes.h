// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction written for this project from the pinned image listing; no body copied or adapted.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none declared.
// BSFixedString, TESForm, TESFullName, TESTexture, TESEyes, TESEyes::InitializeData, TESEyes::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BaseFormComponent, BaseFormComponent::~BaseFormComponent, BaseFormComponent::InitializeDataComponent, BaseFormComponent::ClearDataComponent, BaseFormComponent::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString::data, TESFullName::fullName, TESTexture::textureName, TESForm::sourceFiles, TESForm::formFlags, TESForm::formID, TESForm::inGameFormFlags, TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::unknown1B, TESForm::unknown1C, TESEyes::unknown41, TESEyes::unknown42, TESEyes::unknown44: GUESS(low); no instruction in this unit reads them, so only their size and offset are evidenced
// TESForm::~TESForm, TESTexture::~TESTexture, BSFixedString::~BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESEyes, TESFullName, TESTexture: EXE_RTTI; the layer order and the three vftable slots come from the image RTTI and the listing stores
#pragma once

#include <cstdint>

// BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); 0x8-byte member, only its destructor is called here
class BSFixedString
{
public:
    // BSFixedString::~BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ~BSFixedString();

    // BSFixedString::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    const char* data;  // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "BSFixedString size");

// BaseFormComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the inline empty destructor is needed because the target inlines it into the layer destructors below
class BaseFormComponent
{
public:
    // BaseFormComponent::~BaseFormComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual ~BaseFormComponent() {}  // 00
    // BaseFormComponent::InitializeDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual void InitializeDataComponent() {}  // 01
    // BaseFormComponent::ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual void ClearDataComponent() {}  // 02
    // BaseFormComponent::CopyComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual void CopyComponent(BaseFormComponent* a_rhs) {}  // 03
};
static_assert(sizeof(BaseFormComponent) == 0x8, "BaseFormComponent size");

// TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the layer at 0x00, 0x20 bytes; its destructor stays out of line
class TESForm : public BaseFormComponent
{
public:
    // TESForm::~TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ~TESForm() override;
    // TESForm::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual void InitializeData();  // 04

    // TESForm::sourceFiles: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    void* sourceFiles;  // 08
    // TESForm::formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint32_t formFlags;  // 10
    // TESForm::formID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint32_t formID;  // 14
    // TESForm::inGameFormFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint16_t inGameFormFlags;  // 18
    // TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t formType;  // 1A
    // TESForm::unknown1B: GUESS(low); no instruction in this unit reads the 1B byte, so its position only is evidenced
    std::uint8_t unknown1B;  // 1B
    // TESForm::unknown1C: GUESS(low); no instruction in this unit reads the 1C dword, so its position only is evidenced
    std::uint32_t unknown1C;  // 1C
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");

// TESFullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the layer at 0x20, 0x10 bytes; the target inlines its destructor
class TESFullName : public BaseFormComponent
{
public:
    // TESFullName::~TESFullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ~TESFullName() override {}  // 00

    // TESFullName::fullName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    BSFixedString fullName;  // 08
};
static_assert(sizeof(TESFullName) == 0x10, "TESFullName size");

// TESTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the layer at 0x30, 0x10 bytes; its destructor stays out of line
class TESTexture : public BaseFormComponent
{
public:
    // TESTexture::~TESTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ~TESTexture() override;  // 00

    // TESTexture::textureName: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    BSFixedString textureName;  // 08
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");

// TESEyes: EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class TESEyes : public TESForm, public TESFullName, public TESTexture
{
public:
    // TESEyes::~TESEyes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ~TESEyes() override;  // 00

    // TESEyes::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    void InitializeData() override;  // 04

    // TESEyes::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares an enumeration over uint8
    std::uint8_t flags;  // 40
    // TESEyes::unknown41: GUESS(low); no instruction in this unit reads the 41 byte, so its position only is evidenced
    std::uint8_t unknown41;  // 41
    // TESEyes::unknown42: GUESS(low); no instruction in this unit reads the 42 word, so its position only is evidenced
    std::uint16_t unknown42;  // 42
    // TESEyes::unknown44: GUESS(low); no instruction in this unit reads the 44 dword, so its position only is evidenced
    std::uint32_t unknown44;  // 44
};
static_assert(sizeof(TESEyes) == 0x48, "layout");
