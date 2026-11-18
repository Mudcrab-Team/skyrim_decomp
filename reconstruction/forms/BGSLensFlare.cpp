// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x262e30 BGSLensFlare::InitItemImpl
// 0x262ea0 BGSLensFlare::ClearData
// 0x263000 BGSLensFlare::~BGSLensFlare
#include "BGSLensFlare.h"
// TestBit: GUESS(low); bit-index accessor following the normal card.
inline bool TestBit(std::uint32_t flags,std::uint32_t bit) { return ((flags>>bit)&1)!=0; }



void BGSLensFlare::InitItemImpl() { MemoryScope scope; if(!TestBit(formFlags,3)) MarkLensFlare(this,true); }

