// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x261fc0 BGSHazard::InitializeData
// 0x262730 BGSHazard::~BGSHazard
#include "BGSHazard.h"
BGSHazard::BGSHazard() {}
BGSHazard::~BGSHazard() {}
void BGSHazard::InitializeData() { limit=0; radius=0; lifetime=0; imageSpaceRadius=0; targetInterval=hazardDefaultFloat; hazardFlags=0; spell=nullptr; light=nullptr; sound=nullptr; impactDataSet=nullptr; }

