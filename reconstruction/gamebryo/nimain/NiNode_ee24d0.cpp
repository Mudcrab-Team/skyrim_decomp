// Build id: sse-steam-1-7-104. Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Labels: v2
// NiNode::UpdateDownwardPass: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// RVA 0xee24d0, 419 bytes: NiNode::UpdateDownwardPass (compared)
// Adapted bodies: none
#include "NiNode_ee24d0.h"

void NiNode::UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2)
{
	if (a_data.flags & 1) {
		for (NiTimeController* controller = controllers; controller; controller = controller->next) {
			controller->Update(a_data);
		}
	}

	UpdateWorldData(&a_data);

	std::uint32_t childFlags = a_arg2;
	if (TestBit(FlagByte(), 0)) {
		childFlags |= 1;
	}

	const std::uint32_t count = children._freeIdx;
	std::uint32_t       i = 0;
	if (!TestBit(FlagWord(), 13)) {
		worldBound.radiusBits = 0;
		for (; i < count; ++i) {
			NiAVObject* child = children._data[i];
			if (child) {
				child->UpdateDownwardPass(a_data, childFlags);
				if (child->worldBound.radiusBits != 0) {
					++i;
					worldBound.SetCenterAndRadius(child->worldBound.GetCenter(), child->worldBound.GetRadius());
					break;
				}
			}
		}
	}
	for (; i < count; ++i) {
		NiAVObject* child = children._data[i];
		if (child) {
			child->UpdateDownwardPass(a_data, childFlags);
			if (!TestBit(FlagWord(), 13) && child->worldBound.radiusBits != 0) {
				worldBound.Merge(&child->worldBound);
			}
		}
	}
}
