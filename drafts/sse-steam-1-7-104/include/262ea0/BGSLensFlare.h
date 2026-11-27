// Build: sse-steam-1-7-104
// Exposure detail: (community headers and pinned-image analysis).
// Source exposure: mixed
// Declarations adapt CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Helper spellings and local variable names are inferred; individual labels accompany declarations.
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// BGSLensFlare: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include <cstddef>
#include "TESForm.h"
#include <intrin.h>
class BSLensFlareSpriteRenderData { public: virtual ~BSLensFlareSpriteRenderData(); virtual void DeleteThis(); volatile long refCount; };
// This owned pointer releases its intrusive count atomically before deleting the sprite.
struct LensPointer { BSLensFlareSpriteRenderData* value; ~LensPointer() { auto* owned=value; if(owned && _InterlockedExchangeAdd(&owned->refCount,-1)==1) owned->DeleteThis(); } };
void ClearLensArray(void*);
struct LensArray { ~LensArray(); LensPointer* data; std::uint32_t capacity,allocatorState,count,unknown14; };
struct BSLensFlareRenderData { float fadeDistRadiusScale,colorInfluence; LensArray sprites; };
class BGSLensFlare : public TESForm, public BSLensFlareRenderData { public: BGSLensFlare(); ~BGSLensFlare() override; void InitItemImpl() override; void ClearData() override; }; static_assert(sizeof(BGSLensFlare)==0x40,"lens flare size");
void MarkLensFlare(TESForm*,bool);
extern __declspec(thread) std::uint32_t MemoryTLS;
struct MemoryScope { std::uint32_t saved; MemoryScope() noexcept:saved(MemoryTLS) { MemoryTLS=0x65; } ~MemoryScope(){MemoryTLS=saved;} };
