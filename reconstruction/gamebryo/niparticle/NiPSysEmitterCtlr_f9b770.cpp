// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0xf9b770 NiPSysEmitterCtlr::GetInterpolatorID
#include "NiPSysEmitterCtlr_f9b770.h"

const char* NiPSysEmitterCtlr::GetInterpolatorID(std::uint16_t a_index)
{
	if (a_index == 0) {
		return g_emitterCtlrBirthRateID;
	}
	if (a_index == 1) {
		return g_emitterCtlrEmitterActiveID;
	}
	return nullptr;
}
