// Build: sse-steam-1-7-104
// Exposure detail: (community headers and pinned-image analysis).
// Source exposure: mixed
// Declarations adapt CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Helper spellings and local variable names are inferred; individual labels accompany declarations.
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// BGSPerk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include <cstddef>
#include "TESForm.h"
inline BaseFormComponent::~BaseFormComponent() {}
class BSFixedString { public: BSFixedString(); ~BSFixedString(); const char* value; };
class TESFullName : public BaseFormComponent { public: ~TESFullName() override {} void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual std::uint32_t GetFullNameLength() const; virtual const char* GetFullName() const; BSFixedString fullName; };
class TESDescription : public BaseFormComponent { public: ~TESDescription() override; void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; std::uint32_t fileOffset,descriptionText; };
class TESTexture : public BaseFormComponent { public: virtual ~TESTexture(); void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual std::uint32_t GetMaxAllowedSize(); virtual void GetAsNormalFile(); virtual void GetDefaultPath(); BSFixedString textureName; };
class TESIcon : public TESTexture { public: ~TESIcon() override; };
struct TESCondition { void* head; void Clear(); void Resolve(TESForm*); };
// ArrayOwner, ClearArray, ResetArrayCount, ReleaseArray: GUESS(low); represented heap array ownership.
void ClearArray(void*); void ResetArrayCount(std::uint32_t*); void ReleaseArray(void*);
struct ArrayOwner {
 void** data; std::uint32_t capacity; std::uint32_t allocatorState; std::uint32_t count; std::uint32_t unknown14;
 ~ArrayOwner() { if(data) { ClearArray(this); count=0; } else ResetArrayCount(&count); ReleaseArray(this); }
};
static_assert(sizeof(ArrayOwner)==0x18,"heap array size");
class BGSPerk;
class BGSPerkEntry { public: virtual void Slot0(); virtual void Slot1(); virtual void Slot2(); virtual ~BGSPerkEntry(); virtual void Slot4(); virtual void ClearData(); virtual void InitItem(TESFile*); virtual bool Load(TESFile*); virtual void SetParent(BGSPerk*); };
struct PerkData { bool trait; std::int8_t level,numRanks; bool playable,hidden; };
class BGSPerk : public TESForm, public TESFullName, public TESDescription, public TESIcon { public: void ClearData() override; void InitItemImpl() override; PerkData data; TESCondition perkConditions; ArrayOwner perkEntries; BGSPerk* nextPerk; }; static_assert(sizeof(BGSPerk)==0x80,"perk size");
void* PerkSourceFile(TESForm*,std::int32_t); void ResolvePerkID(std::uint32_t*,void*); TESForm* LookupPerkID(std::uint32_t); void MarkPerk(TESForm*,bool);
