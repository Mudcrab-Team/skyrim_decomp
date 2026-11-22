// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLensFlare: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim_shared/forms/TESForm.h"
#include <intrin.h>
class BSLensFlareSpriteRenderData { public: virtual ~BSLensFlareSpriteRenderData(); virtual void DeleteThis(); volatile long refCount; };
// This owned pointer releases its intrusive count atomically before deleting the sprite.
struct LensPointer { BSLensFlareSpriteRenderData* value; ~LensPointer() { if(value && _InterlockedExchangeAdd(&value->refCount,-1)==1) value->DeleteThis(); } };
void ClearLensArray(void*);
struct LensArray { ~LensArray(); LensPointer* data; std::uint32_t capacity,allocatorState,count,unknown14; };
struct BSLensFlareRenderData { float fadeDistRadiusScale,colorInfluence; LensArray sprites; };
class BGSLensFlare : public TESForm, public BSLensFlareRenderData { public: BGSLensFlare(); ~BGSLensFlare() override; void InitItemImpl() override; void ClearData() override; }; static_assert(sizeof(BGSLensFlare)==0x40,"lens flare size");
void MarkLensFlare(TESForm*,bool);
extern __declspec(thread) std::uint32_t MemoryTLS;
struct MemoryScope { std::uint32_t saved; MemoryScope():saved(MemoryTLS) { MemoryTLS=0x65; } ~MemoryScope(){MemoryTLS=saved;} };

