// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0xfa0b10 NiPSysModifierCtlr::SetTarget
#include "NiPSysModifierCtlr_fa0b10.h"

void NiPSysModifierCtlr::SetTarget(NiObjectNET* a_target)
{
	modifier = nullptr;
	NiTimeController::SetTarget(a_target);
	if (target) {
		GetModifierPointer();
	}
}
