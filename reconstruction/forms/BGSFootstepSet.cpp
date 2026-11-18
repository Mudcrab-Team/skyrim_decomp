// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x31d370 BGSFootstepSet::~BGSFootstepSet
// 0x31cd90 BGSFootstepSet::InitializeData
// 0x31d180 BGSFootstepSet::InitItemImpl
#include "BGSFootstepSet.h"
// TestBit: GUESS(low); bit-index accessor following the normal card.
inline bool TestBit(std::uint32_t flags,std::uint32_t bit) { return ((flags>>bit)&1)!=0; }
BGSFootstepSet::BGSFootstepSet() { formType=static_cast<FormType>(0x6f); }

void BGSFootstepSet::InitializeData() { BGSFootstepSet{}; }


