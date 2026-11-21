// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x28f900 BGSEncounterZone::SetDetachTime
// Adapted bodies: none
#include "BGSEncounterZone_28f900.h"

void BGSEncounterZone::SetDetachTime(std::uint32_t a_time)
{
	detachTime = a_time;
	AddChange(ChangeFlags::kGameData);
}
