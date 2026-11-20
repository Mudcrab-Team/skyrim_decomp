// Source exposure: mixed (pinned image, RTTI, and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the partial prefix and typed slots follow the cited TESForm declarations.
// TESForm: EXE_RTTI
// TESFile, FormType, formFlags, formID, formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Load, LoadEdit, GetFile, GetDescriptionOwnerFile, GetSavedFormType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetKnown, GetRandomAnim, GetPlayable, GetDangerous, QHasCurrents, GetObstacle, GetOnLocalMap, GetMustUpdate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FunctionSlot declarations, padding, Function1e0d00, Function1e6900, Function1ce0d0: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class TESForm;
enum class FormType : std::uint8_t;

class TESFile
{
public:
    bool Function1ce0d0(TESForm* form);
};

class TESForm
{
public:
    virtual ~TESForm();
    virtual void FunctionSlot01();  // 01
    virtual void FunctionSlot02();  // 02
    virtual void FunctionSlot03();  // 03
    virtual void FunctionSlot04();  // 04
    virtual void FunctionSlot05();  // 05
    virtual bool Load(TESFile* file);  // 06
    virtual void FunctionSlot07();  // 07
    virtual bool LoadEdit(TESFile* file);  // 08
    virtual void FunctionSlot09();  // 09
    virtual void FunctionSlot0A();  // 0A
    virtual void FunctionSlot0B();  // 0B
    virtual void FunctionSlot0C();  // 0C
    virtual void FunctionSlot0D();  // 0D
    virtual void FunctionSlot0E();  // 0E
    virtual void FunctionSlot0F();  // 0F
    virtual void FunctionSlot10();  // 10
    virtual void FunctionSlot11();  // 11
    virtual void FunctionSlot12();  // 12
    virtual void FunctionSlot13();  // 13
    virtual TESFile* GetDescriptionOwnerFile() const;  // 14
    virtual FormType GetSavedFormType() const;  // 15
    virtual void FunctionSlot16();  // 16
    virtual bool GetKnown() const;  // 17
    virtual bool GetRandomAnim() const;  // 18
    virtual bool GetPlayable() const;  // 19
    virtual void FunctionSlot1A();  // 1A
    virtual bool GetDangerous() const;  // 1B
    virtual bool QHasCurrents() const;  // 1C
    virtual bool GetObstacle() const;  // 1D
    virtual void FunctionSlot1E();  // 1E
    virtual bool GetOnLocalMap() const;  // 1F
    virtual bool GetMustUpdate() const;  // 20

    static bool Function1e0d00(const TESForm* form);
    bool Function1e6900(TESFile& file);

private:
    TESFile* GetFile(std::int32_t index) const;

    std::uint8_t padding008[8];
    std::uint32_t formFlags;
    std::uint32_t formID;
    std::uint8_t padding018[2];
    FormType formType;
};
