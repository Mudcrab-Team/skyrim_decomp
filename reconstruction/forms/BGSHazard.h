// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSHazard: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
#include "../forms/TESForm.h"
inline BaseFormComponent::~BaseFormComponent() {}
class BSFixedString { public: BSFixedString(); ~BSFixedString(); const char* value; };
class TESFullName : public BaseFormComponent { public: ~TESFullName() override {} void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual std::uint32_t GetFullNameLength() const; virtual const char* GetFullName() const; BSFixedString fullName; };
class TESModel : public BaseFormComponent { public: ~TESModel() override; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual const char* GetModel() const; virtual void SetModel(const char*); virtual void* GetAsModelTextureSwap(); BSFixedString model; void* textures; std::uint32_t* addons; std::uint16_t numTextures,numAddons; };
class TESObject : public TESForm {};
class TESBoundObject : public TESObject { public: virtual ~TESBoundObject(); std::int16_t boundMin[3],boundMax[3]; };
class BGSPreloadable : public BaseFormComponent { public:  void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual void Preload(); };
class TESImageSpaceModifiableForm : public BaseFormComponent { public:  void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; void* imageSpaceModifier; };
class BGSHazard : public TESBoundObject, public TESFullName, public TESModel, public BGSPreloadable, public TESImageSpaceModifiableForm { public: BGSHazard(); ~BGSHazard() override; void InitializeData() override; std::uint32_t limit; float radius,lifetime,imageSpaceRadius,targetInterval; std::uint32_t hazardFlags; void* spell; void* light; void* impactDataSet; void* sound; };
static_assert(sizeof(BGSHazard)==0xB8,"hazard represented size");
extern float hazardDefaultFloat;

