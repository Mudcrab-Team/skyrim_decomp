// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BGSDualCastData, BGSDualCastData::~BGSDualCastData, BGSDualCastData::Load, BGSDualCastData::InitItemImpl, TESObject::~TESObject, TESObject::IsObject, TESObject::GetRefCount, TESObject::Unk_3B, TESObject::IsBoundAnimObject, TESObject::GetWaterType, TESObject::IsAutoCalc, TESObject::SetAutoCalc, TESObject::Clone3D, TESObject::UnClone3D, TESObject::IsMarker, TESObject::IsOcclusionMarker, TESObject::ReplaceModel, TESObject::IncRef, TESObject::DecRef, TESObject::LoadGraphics, TESBoundObject::~TESBoundObject, TESBoundObject::LoadObjectBound, TESBoundObject::IsBoundObject, TESBoundObject::Activate, TESBoundObject::Clone3D, TESBoundObject::ReplaceModel, TESBoundObject::SetObjectVoiceType, TESBoundObject::GetObjectVoiceType, TESBoundObject::GetActivateText, TESBoundObject::CalculateDoFavor, TESBoundObject::HandleRemoveItemFromContainer, TESBoundObject::OnRemove3D, TESBoundObject::OnCheckModels, TESBoundObject::OnCopyReference, TESBoundObject::OnFinishScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObject, TESBoundObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); main's TESObject.h and TESBoundObject.h declare no virtual slots, so the slots this unit needs are repeated here
// TESWaterForm, NiAVObject, BGSVoiceType, BSString, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); forward declarations only
// unknown20, unknown28, unknown30, unknown38, unknown40, unknown48, unknown50, unknown58: GUESS(low); the compared destructor reads none of them
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/TESForm.h"

class TESWaterForm;
class NiAVObject;
class BGSVoiceType;
class BSString;
class Actor;

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

class BGSDualCastData : public TESBoundObject
{
public:
    virtual ~BGSDualCastData();  // compared: 0x1474f0  // slot 00
    bool Load(TESFile* a_mod) override;  // 06
    void InitItemImpl() override;  // 13
    BGSDualCastData();

    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
};
static_assert(sizeof(BGSDualCastData) == 0x60, "BGSDualCastData size");
