// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// NiPSysEmitterCtlr, GetInterpolatorID: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_emitterCtlrBirthRateID, g_emitterCtlrEmitterActiveID: GUESS(low); the two interpolator id strings the image reads from .data
#pragma once

#include <cstdint>

extern const char* g_emitterCtlrBirthRateID;
extern const char* g_emitterCtlrEmitterActiveID;

class NiPSysEmitterCtlr
{
public:
	const char* GetInterpolatorID(std::uint16_t a_index);
};
