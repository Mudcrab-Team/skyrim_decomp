// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAddonNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
#include "../forms/TESForm.h"
inline BaseFormComponent::~BaseFormComponent() {}
class BSFixedString { public: BSFixedString(); ~BSFixedString(); const char* value; };
class TESModel : public BaseFormComponent { public: ~TESModel() override; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual const char* GetModel() const; virtual void SetModel(const char*); virtual void* GetAsModelTextureSwap(); BSFixedString model; void* textures; std::uint32_t* addons; std::uint16_t numTextures,numAddons; };
class TESObject : public TESForm {};
class TESBoundObject : public TESObject { public: virtual ~TESBoundObject(); std::int16_t boundMin[3],boundMax[3]; };
class TESModelTextureSwap : public TESModel { public: ~TESModelTextureSwap() override; void CopyComponent(BaseFormComponent*) override; void* alternateTextures; std::uint32_t numAlternateTextures; };
class TESModelRDT : public TESModel { public: ~TESModelRDT() override; };
class BGSAddonNode : public TESBoundObject, public TESModelTextureSwap { public: BGSAddonNode(); ~BGSAddonNode() override; void InitItemImpl() override; std::uint32_t index; void* sound; std::uint16_t masterParticleSystemCap; std::uint16_t flags; }; static_assert(sizeof(BGSAddonNode)==0x80,"addon node size");
void ResolveAddonModels(TESModelTextureSwap*,TESForm*); void* AddonSourceFile(TESForm*,std::int32_t); void ResolveAddonID(std::uint32_t*,void*); void* LookupAddonSound(std::uint32_t); void MarkAddonNode(TESForm*,bool); extern void* AddonDataHandler; void RemoveAddonNode(void*,BGSAddonNode*);

