// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0x274bc0 TESObjectLIGH::Function274bc0
// Adapted bodies: none
#include "TESObjectLIGH_274bc0.h"

void TESObjectLIGH::Function274bc0(LightParam* a_param, std::uint32_t a_extra)
{
	if (a_param) {
		Function274be0(a_param, a_extra, a_param->value);
	}
}
