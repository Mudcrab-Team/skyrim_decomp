// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0x25b7f0 BGSAddonNode::InitializeData
// Adapted bodies: none
#include "BGSAddonNode_25b7f0.h"

void BGSAddonNode::InitializeData()
{
	sound = nullptr;
	memset(&data, 0, sizeof(data));
}
