// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESBipedModelForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
#include "../forms/TESForm.h"
inline BaseFormComponent::~BaseFormComponent() {}
class BSFixedString { public: BSFixedString(); ~BSFixedString(); const char* value; };
class TESModel : public BaseFormComponent { public: ~TESModel() override; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual const char* GetModel() const; virtual void SetModel(const char*); virtual void* GetAsModelTextureSwap(); BSFixedString model; void* textures; std::uint32_t* addons; std::uint16_t numTextures,numAddons; };
class TESTexture : public BaseFormComponent { public: virtual ~TESTexture(); void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual std::uint32_t GetMaxAllowedSize(); virtual void GetAsNormalFile(); virtual void GetDefaultPath(); BSFixedString textureName; };
class TESIcon : public TESTexture { public: ~TESIcon() override; };
class TESModelTextureSwap : public TESModel { public: ~TESModelTextureSwap() override; void CopyComponent(BaseFormComponent*) override; void* alternateTextures; std::uint32_t numAlternateTextures; };
class TESModelRDT : public TESModel { public: ~TESModelRDT() override; };
class BGSMessageIcon : public BaseFormComponent { public: ~BGSMessageIcon() override ; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; TESIcon icon; };
class TESBipedModelForm : public BaseFormComponent { public: ~TESBipedModelForm() override; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; TESModelTextureSwap worldModels[2]; TESIcon inventoryIcons[2]; BGSMessageIcon messageIcons[2]; TESModelRDT constraintTemplate; }; static_assert(sizeof(TESBipedModelForm)==0xF0,"biped model component size");

