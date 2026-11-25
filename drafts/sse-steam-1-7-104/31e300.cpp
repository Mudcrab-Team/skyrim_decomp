// Near miss: 0.0% | other
// Build: sse-steam-1-7-104
// Exposure detail: (community headers and pinned-image analysis).
// Source exposure: mixed
// Declarations adapt CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Helper spellings and local variable names are inferred; individual labels accompany declarations.
//
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x31e300 BGSImpactDataSet::ClearData

#include "include/31e300/BGSImpactDataSet.h"
// TestBit: GUESS(low); bit-index accessor following the normal card.
inline bool TestBit(std::uint32_t flags,std::uint32_t bit) { return ((flags>>bit)&1)!=0; }
BGSImpactDataSet::BGSImpactDataSet() {}
BGSImpactDataSet::~BGSImpactDataSet() {}
void BGSImpactDataSet::InitItemImpl() { MemoryScope scope; if(!TestBit(formFlags,3)) { auto* map=&impactMap; ResolveImpactMap(ImpactDataHandler,0x63,&map); MarkImpactSet(this,true); } }
void BGSImpactDataSet::ClearData() { MemoryScope scope; auto* map=&impactMap.tail; auto* entry=map->entries; std::uint32_t capacity; if(entry) { capacity=impactMap.tail.capacity; if(capacity) { do { --capacity; if(entry->next) { DestroyImpactEntry(entry,&entry->value); entry->next=nullptr; } ++entry; } while(capacity); capacity=impactMap.tail.capacity; } } else { impactMap.tail.capacity=0; capacity=0; } impactMap.tail.freeCount=capacity; impactMap.tail.good=capacity; }
