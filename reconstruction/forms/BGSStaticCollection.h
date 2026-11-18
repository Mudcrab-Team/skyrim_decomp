// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names, bases, members and declarations
// Source exposure: mixed (community declarations and the contributor-owned pack;
// bases, sizes and slots are community hypotheses).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSStaticCollection, BGSStaticCollection::ClearData, BGSStaticCollection::~BGSStaticCollection, BGSStaticCollection::Load, BGSStaticCollection::InitItemImpl, TESObject::~TESObject, TESObject::IsObject, TESObject::GetRefCount, TESObject::Unk_3B, TESObject::IsBoundAnimObject, TESObject::GetWaterType, TESObject::IsAutoCalc, TESObject::SetAutoCalc, TESObject::Clone3D, TESObject::UnClone3D, TESObject::IsMarker, TESObject::IsOcclusionMarker, TESObject::ReplaceModel, TESObject::IncRef, TESObject::DecRef, TESObject::LoadGraphics, TESBoundObject::~TESBoundObject, TESBoundObject::LoadObjectBound, TESBoundObject::IsBoundObject, TESBoundObject::Activate, TESBoundObject::Clone3D, TESBoundObject::ReplaceModel, TESBoundObject::SetObjectVoiceType, TESBoundObject::GetObjectVoiceType, TESBoundObject::GetActivateText, TESBoundObject::CalculateDoFavor, TESBoundObject::HandleRemoveItemFromContainer, TESBoundObject::OnRemove3D, TESBoundObject::OnCheckModels, TESBoundObject::OnCopyReference, TESBoundObject::OnFinishScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESObject, TESBoundObject, TESWaterForm, NiAVObject, BGSVoiceType, BSString, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSFixedString, TESModel, TESModelTextureSwap, BGSTextureSet, NiNPShortPoint3, BOUND_DATA: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// TESBoundObject::boundData, pad2C, BOUND_DATA::boundMin, boundMax, NiNPShortPoint3::x, y, z, TESModel::model, textures, addons, numTextures, numAddons, pad24, TESModelTextureSwap::alternateTextures, numAlternateTextures, pad34, AlternateTexture::textureSet, index3D, unk0C, name3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSFixedString::_data, BSResource::ID: STANDIN GUESS(low); layout-only placeholders
// MemoryContextScope, g_memoryContext: STANDIN GUESS(low); the thread-local context value the compared function saves, sets and restores
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

struct NiNPShortPoint3
{
    std::int16_t x;  // 0
    std::int16_t y;  // 2
    std::int16_t z;  // 4
};
static_assert(sizeof(NiNPShortPoint3) == 0x6, "NiNPShortPoint3 size");

struct BOUND_DATA
{
    NiNPShortPoint3 boundMin;  // 0
    NiNPShortPoint3 boundMax;  // 6
};
static_assert(sizeof(BOUND_DATA) == 0xC, "BOUND_DATA size");

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
    BOUND_DATA boundData;  // 20
    std::uint32_t pad2C;  // 2C
};
static_assert(sizeof(TESBoundObject) == 0x30, "TESBoundObject size");

class BGSTextureSet;
class TESModelTextureSwap;

class BSFixedString
{
public:
    const char* _data;  // 00
};
static_assert(sizeof(BSFixedString) == 0x8, "BSFixedString size");

namespace BSResource
{
    struct ID
    {
        std::uint32_t file;  // 00
        std::uint32_t ext;  // 04
        std::uint32_t dir;  // 08
    };
    static_assert(sizeof(ID) == 0xC, "BSResource::ID size");
}

class TESModel : public BaseFormComponent
{
public:
    ~TESModel() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    virtual const char* GetModel() const;  // 04
    virtual void SetModel(const char* a_model);  // 05
    virtual TESModelTextureSwap* GetAsModelTextureSwap();  // 06

    BSFixedString model;  // 08
    BSResource::ID* textures;  // 10
    std::uint32_t* addons;  // 18
    std::uint16_t numTextures;  // 20
    std::uint16_t numAddons;  // 22
    std::uint32_t pad24;  // 24
};
static_assert(sizeof(TESModel) == 0x28, "TESModel size");

class TESModelTextureSwap : public TESModel
{
public:
    struct AlternateTexture
    {
        BGSTextureSet* textureSet;  // 00
        std::uint32_t index3D;  // 08
        std::uint32_t unk0C;  // 0C
        BSFixedString name3D;  // 10
    };
    static_assert(sizeof(AlternateTexture) == 0x18, "AlternateTexture size");

    ~TESModelTextureSwap() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02
    void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
    TESModelTextureSwap* GetAsModelTextureSwap() override;  // 06

    AlternateTexture* alternateTextures;  // 28
    std::uint32_t numAlternateTextures;  // 30
    std::uint32_t pad34;  // 34
};
static_assert(sizeof(TESModelTextureSwap) == 0x38, "TESModelTextureSwap size");

// The engine keeps a per-thread memory-context value; ClearData sets it for the duration of the call and restores it
// afterwards, including when unwinding.
extern __declspec(thread) std::uint32_t g_memoryContext;

class MemoryContextScope
{
public:
    explicit MemoryContextScope(std::uint32_t a_value) : saved(g_memoryContext) { g_memoryContext = a_value; }
    ~MemoryContextScope() { g_memoryContext = saved; }

private:
    std::uint32_t saved;
};

class BGSStaticCollection : public TESBoundObject, public TESModelTextureSwap
{
public:
    ~BGSStaticCollection() override;  // 00
    void ClearData() override;  // 05, compared: 0x266b20
    bool Load(TESFile* a_mod) override;  // 06
    void InitItemImpl() override;  // 13

};
static_assert(sizeof(BGSStaticCollection) == 0x68, "BGSStaticCollection size");
