// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/TESForm.h for TESForm.
// BGSTextureSet, BGSTextureSet::InitializeData, BGSTextureSet::~BGSTextureSet, BGSTextureSet::ClearData, BGSTextureSet::Load, BGSTextureSet::Clone3D, BGSTextureSet::UnClone3D, TESObject::~TESObject, TESObject::IsObject, TESObject::GetRefCount, TESObject::Unk_3B, TESObject::IsBoundAnimObject, TESObject::GetWaterType, TESObject::IsAutoCalc, TESObject::SetAutoCalc, TESObject::Clone3D, TESObject::UnClone3D, TESObject::IsMarker, TESObject::IsOcclusionMarker, TESObject::ReplaceModel, TESObject::IncRef, TESObject::DecRef, TESObject::LoadGraphics, TESBoundObject::~TESBoundObject, TESBoundObject::LoadObjectBound, TESBoundObject::IsBoundObject, TESBoundObject::Activate, TESBoundObject::Clone3D, TESBoundObject::ReplaceModel, TESBoundObject::SetObjectVoiceType, TESBoundObject::GetObjectVoiceType, TESBoundObject::GetActivateText, TESBoundObject::CalculateDoFavor, TESBoundObject::HandleRemoveItemFromContainer, TESBoundObject::OnRemove3D, TESBoundObject::OnCheckModels, TESBoundObject::OnCopyReference, TESBoundObject::OnFinishScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObject, TESBoundObject, NiAVObject, TESWaterForm, BGSVoiceType, BSString, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20, unknown30, unknownC0, unknownC8: GUESS(low)
// textures: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the eight-entry array at 0x40
// TESTexture, TESTexture::InitializeDataComponent, BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a polymorphic component of 0x10 bytes whose virtual slot 1 the loop calls
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class NiAVObject;
class TESWaterForm;
class BGSVoiceType;
class BSString;
class Actor;


class BSFixedString
{
public:
    const char* data;  // 00
};

class TESTexture : public BaseFormComponent
{
public:
    ~TESTexture() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(BaseFormComponent* a_rhs) override;

    BSFixedString name;  // 08
};
static_assert(sizeof(TESTexture) == 0x10, "TESTexture size");

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
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
};
static_assert(sizeof(TESBoundObject) == 0x30, "TESBoundObject size");

class BGSTextureSet : public TESBoundObject
{
public:
    ~BGSTextureSet() override;  // 00
    virtual void InitializeData();  // compared: 0x32d090  // slot 04
    void ClearData() override;  // 05
    bool Load(TESFile* a_mod) override;  // 06
    NiAVObject* Clone3D(TESObjectREFR* a_ref, bool a_arg3) override;  // 40
    void UnClone3D(TESObjectREFR* a_ref) override;  // 41

    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    TESTexture textures[8];  // 40
    std::uint64_t unknownC0;  // C0
    std::uint16_t unknownC8;  // C8
    std::uint16_t unknownCA;  // CA
    std::uint16_t unknownCC;  // CC
    std::uint16_t unknownCE;  // CE
    std::uint64_t unknownD0;  // D0
    std::uint64_t unknownD8;  // D8
    std::uint64_t unknownE0;  // E0
    std::uint64_t unknownE8;  // E8
    std::uint64_t unknownF0;  // F0
    std::uint64_t unknownF8;  // F8
    std::uint64_t unknown100;  // 100
    std::uint64_t unknown108;  // 108
    std::uint64_t unknown110;  // 110
    std::uint64_t unknown118;  // 118
    std::uint64_t unknown120;  // 120
    std::uint64_t unknown128;  // 128
};
static_assert(sizeof(BGSTextureSet) == 0x130, "BGSTextureSet size");
