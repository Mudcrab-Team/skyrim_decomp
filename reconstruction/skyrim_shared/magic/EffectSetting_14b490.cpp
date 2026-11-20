// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// 0x14b490 EffectSetting::GetObjectTypeName
#include "EffectSetting_14b490.h"

const char* EffectSetting::GetObjectTypeName() const
{
	return g_archetypeInfo[archetype].name;
}
