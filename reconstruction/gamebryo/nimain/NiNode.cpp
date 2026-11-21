// Code origin: original reconstruction from the pinned image listing; declarations from CommonLibSSE-NG (MIT). No community body copied.
// 0xee2310 NiNode::Functionee2310
// 0xfde7a0 NiNode::Functionfde7a0
// Adapted bodies: none
// Source exposure: mixed (binary-analysis, community headers).
// Origin: original reconstruction; types informed by CommonLibSSE-NG.
// NiNode: EXE_RTTI
// NiNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function4182a0, UpdateFirst, UpdateSecond, Function152a290, Function14e7f80, Functionfde7a0, UpdateFloat, QueryFlag, UpdateNode, Function6e9a50, GetPackageThatIsRunning, GetSpecialPackage, GetRunningOverride, Function639890, ConvertPosition, CountPosition: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionee2310: GUESS(low); the unit's task name for the compared routine
// PerformOpFunc, operator(), PerformOp, children, _data, _size: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#include "NiNode.h"

bool NiNode::Functionfde7a0() { bool value = false; QueryFlag(&value); return value; }

void NiNode::Functionee2310(PerformOpFunc& a_func)
{
	if (a_func(this)) {
		const std::uint16_t count = children._size;
		for (std::uint16_t i = 0; i < count; ++i) {
			NiAVObject* child = children._data[i];
			if (child) {
				child->PerformOp(a_func);
			}
		}
	}
}
