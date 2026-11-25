// Build: sse-steam-1-7-104
// Exposure detail: (community headers and pinned-image analysis).
// Source exposure: mixed
// Declarations adapt CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Helper spellings and local variable names are inferred; individual labels accompany declarations.
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// BGSImpactDataSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include <cstddef>
#include "TESForm.h"
inline BaseFormComponent::~BaseFormComponent() {}
class BGSPreloadable : public BaseFormComponent { public: ~BGSPreloadable() override {} void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual void Preload(); };
struct ImpactEntry { const void* key; void* value; ImpactEntry* next; };
struct ImpactTail { ~ImpactTail(); std::uint32_t unknown00,capacity,freeCount,good; ImpactEntry* sentinel; std::uint64_t allocatorState; ImpactEntry* entries; };
struct ImpactMap { std::uint64_t unknown00; ImpactTail tail; };
class BGSImpactDataSet : public TESForm, public BGSPreloadable { public: BGSImpactDataSet(); ~BGSImpactDataSet() override; void InitItemImpl() override; void ClearData() override; ImpactMap impactMap; }; static_assert(sizeof(BGSImpactDataSet)==0x58,"impact data set size");
void DestroyImpactEntry(ImpactEntry*,void**); void ResolveImpactMap(void*,std::uint8_t,ImpactMap**); extern void* ImpactDataHandler; void MarkImpactSet(TESForm*,bool);
extern __declspec(thread) std::uint32_t MemoryTLS;
struct MemoryScope { std::uint32_t saved; MemoryScope() noexcept:saved(MemoryTLS) { MemoryTLS=0x65; } ~MemoryScope() noexcept {MemoryTLS=saved;} };
