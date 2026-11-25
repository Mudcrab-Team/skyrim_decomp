// Near miss: 17.59% | other
// Build: sse-steam-1-7-104
// Exposure detail: (community headers and pinned-image analysis).
// Source exposure: mixed
// Declarations adapt CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Helper spellings and local variable names are inferred; individual labels accompany declarations.
//
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x396bf0 BGSPerk::InitItemImpl

#include "include/396bf0/BGSPerk.h"
inline bool TestBit(std::uint32_t value,std::uint32_t bit) { return ((value>>bit)&1)!=0; }
void BGSPerk::ClearData() { auto* array=&perkEntries; if(array->count) { auto** entry=reinterpret_cast<BGSPerkEntry**>(perkEntries.data); auto** end=entry+perkEntries.count; while(entry!=end) { auto* owned=*entry++; if(owned) delete owned; } } if(array->data) { ClearArray(array); array->count=0; } return perkConditions.Clear(); }
void BGSPerk::InitItemImpl() { if(!TestBit(formFlags,3)) { perkConditions.Resolve(this); if(perkEntries.count) { auto** entry=reinterpret_cast<BGSPerkEntry**>(perkEntries.data); auto** end=entry+perkEntries.count; while(entry!=end) { auto* owned=*entry++; if(owned) owned->SetParent(this); } } std::uint32_t id=static_cast<std::uint32_t>(reinterpret_cast<std::uintptr_t>(nextPerk)); if(id) { ResolvePerkID(&id,PerkSourceFile(this,-1)); nextPerk=dynamic_cast<BGSPerk*>(LookupPerkID(id)); } MarkPerk(this,true); } }
