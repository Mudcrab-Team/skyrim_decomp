// Near miss: 0.0% | other
// Build: sse-steam-1-7-104
// Exposure detail: (community headers and pinned-image analysis).
// Source exposure: mixed
// Declarations adapt CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Helper spellings and local variable names are inferred; individual labels accompany declarations.
//
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x262ea0 BGSLensFlare::ClearData

#include "include/262ea0/BGSLensFlare.h"
// TestBit: GUESS(low); bit-index accessor following the normal card.
inline bool TestBit(std::uint32_t flags,std::uint32_t bit) { return ((flags>>bit)&1)!=0; }
BGSLensFlare::BGSLensFlare() {}
BGSLensFlare::~BGSLensFlare() { BGSLensFlare::ClearData(); }
void BGSLensFlare::ClearData() { auto* array=&sprites; auto* entry=sprites.data; if(entry) { auto length=array->count; if(length) { std::uint64_t remaining=length; do { entry->~LensPointer(); ++entry; } while(--remaining); } ClearLensArray(array); array->count=0; } }
void BGSLensFlare::InitItemImpl() { MemoryScope scope; if(!TestBit(formFlags,3)) MarkLensFlare(this,true); }
