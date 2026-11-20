// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x31f620 BGSImpactDataSet::~BGSImpactDataSet
// 0x31e5f0 BGSImpactDataSet::InitItemImpl
// 0x31e300 BGSImpactDataSet::ClearData
#include "BGSImpactDataSet.h"
// TestBit: GUESS(low); bit-index accessor following the normal card.
inline bool TestBit(std::uint32_t flags,std::uint32_t bit) { return ((flags>>bit)&1)!=0; }
BGSImpactDataSet::BGSImpactDataSet() {}
BGSImpactDataSet::~BGSImpactDataSet() {}
void BGSImpactDataSet::InitItemImpl() { MemoryScope scope; if(!TestBit(formFlags,3)) { auto* map=&impactMap; ResolveImpactMap(ImpactDataHandler,0x63,&map); MarkImpactSet(this,true); } }


