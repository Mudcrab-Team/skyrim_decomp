// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BGSSaveFormBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BGSSaveGameBuffer: STANDIN EXE_RTTI
// BGSSaveFormBuffer::GetActor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSaveGameBuffer::GetForm, BGSSaveGameBuffer::GetReference: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm::formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offset 0x1A matches NG
// FormType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); underlying type uint8 as NG declares
// FormType::ActorCharacter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); value 0x3E as NG declares
// BGSSaveGameBuffer::~BGSSaveGameBuffer, unknown08, unknown18, TESForm::unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class Actor;
class TESObjectREFR;
class TESForm;

enum class FormType : std::uint8_t
{
    ActorCharacter = 0x3E,
};

class TESForm
{
public:
    virtual ~TESForm() = default;
    std::uint8_t unknown08[0x12];  // 08
    FormType     formType;         // 1A
};
static_assert(offsetof(TESForm, formType) == 0x1A, "TESForm::formType offset");

class TESObjectREFR : public TESForm
{
};

class Actor : public TESObjectREFR
{
};

class BGSSaveGameBuffer
{
public:
    // SaveDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only.
    // This target call passes four arguments rather than the community wrapper's two.
    // a_data, a_size, a_count, a_flags: GUESS(low); parameter names for the observed call shape.
    void SaveDataEndian(const void* a_data, std::uint32_t a_size, std::uint32_t a_count, std::uint32_t a_flags);
    virtual ~BGSSaveGameBuffer() = default;
    virtual TESForm*       GetForm();       // slot 01, declared only
    virtual TESObjectREFR* GetReference();  // slot 02, declared only
    std::uint8_t unknown08[0x10];           // 08
};
static_assert(sizeof(BGSSaveGameBuffer) == 0x18, "BGSSaveGameBuffer size");

class BGSSaveFormBuffer : public BGSSaveGameBuffer
{
public:
    virtual void* GetForm() const;
    virtual Actor* GetActor();  // compared: 0x639860

    std::uint8_t unknown18[0x10];
    // member: GUESS(low); accepted getter storage at offset 0x28
    void* member;  // 28
};
static_assert(sizeof(BGSSaveFormBuffer) == 0x30, "BGSSaveFormBuffer size");
