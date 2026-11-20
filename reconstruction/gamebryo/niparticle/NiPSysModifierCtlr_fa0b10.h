// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// NiTimeController, SetTarget, target, NiObjectNET: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysModifierCtlr: STANDIN EXE_RTTI
// modifier, GetModifierPointer: GUESS(low); a cached pointer the image clears before retargeting and refreshes afterwards
#pragma once

#include <cstdint>

class NiObjectNET;
class NiPSysModifier;

class NiTimeController
{
public:
	void SetTarget(NiObjectNET* a_target);

	std::uint8_t unk00[0x38];  // 00
	NiObjectNET* target;       // 38
};

class NiPSysModifierCtlr : public NiTimeController
{
public:
	void SetTarget(NiObjectNET* a_target);
	void GetModifierPointer();

	std::uint8_t    unk40[0x18];  // 40
	NiPSysModifier* modifier;     // 58
};
