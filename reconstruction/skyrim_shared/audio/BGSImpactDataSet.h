// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSImpactDataSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESForm.h"
inline BaseFormComponent::~BaseFormComponent() {}
class BGSPreloadable : public BaseFormComponent { public: ~BGSPreloadable() override {} void InitializeDataComponent() override; void ClearDataComponent() override; void CopyComponent(BaseFormComponent*) override; virtual void Preload(); };
struct ImpactEntry { const void* key; void* value; ImpactEntry* next; };
struct ImpactTail { ~ImpactTail(); std::uint32_t unknown00,capacity,freeCount,good; ImpactEntry* sentinel; std::uint64_t allocatorState; ImpactEntry* entries; };
struct ImpactMap { std::uint64_t unknown00; ImpactTail tail; };
class BGSImpactDataSet : public TESForm, public BGSPreloadable { public: BGSImpactDataSet(); ~BGSImpactDataSet() override; void InitItemImpl() override; void ClearData() override; ImpactMap impactMap; }; static_assert(sizeof(BGSImpactDataSet)==0x58,"impact data set size");
void DestroyImpactEntry(ImpactEntry*,void**); void ResolveImpactMap(void*,std::uint8_t,ImpactMap**); extern void* ImpactDataHandler; void MarkImpactSet(TESForm*,bool);
extern __declspec(thread) std::uint32_t MemoryTLS;
struct MemoryScope { std::uint32_t saved; MemoryScope():saved(MemoryTLS) { MemoryTLS=0x65; } ~MemoryScope(){MemoryTLS=saved;} };

