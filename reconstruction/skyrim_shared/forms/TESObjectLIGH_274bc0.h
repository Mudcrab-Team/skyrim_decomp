// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// TESObjectLIGH: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// LightParam, LightParam::value, Function274bc0, Function274be0, a_extra: GUESS(low); the callee at 0x274be0 takes this, the parameter, a third argument passed through and the float at +0x8
#pragma once

#include <cstdint>

struct LightParam
{
	std::uint8_t unknown00[0x8];  // 00
	float        value;           // 08
};
static_assert(sizeof(LightParam) == 0xC, "LightParam size");

class TESObjectLIGH
{
public:
	void Function274bc0(LightParam* a_param, std::uint32_t a_extra);
	void Function274be0(LightParam* a_param, std::uint32_t a_extra, float a_value);
};
