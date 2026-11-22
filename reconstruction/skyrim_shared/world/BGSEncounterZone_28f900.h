// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BGSEncounterZone, BGSEncounterZone::ChangeFlags, kGameData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSEncounterZone::SetDetachTime: CRASHLOGGER_PDB(59818@2026.10.24)
// unknown20, detachTime, unknown3C: GUESS(low); the first four bytes of the game data at 0x38 are the detach time
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class BGSEncounterZone : public TESForm
{
public:
	struct ChangeFlags
	{
		enum ChangeFlag : std::uint32_t
		{
			kGameData = static_cast<std::uint32_t>(1) << 31
		};
	};

	void SetDetachTime(std::uint32_t a_time);

	std::uint8_t  unknown20[0x18];  // 20
	std::uint32_t detachTime;       // 38
	std::uint8_t  unknown3C[0xC];   // 3C
};
static_assert(sizeof(BGSEncounterZone) == 0x48, "layout");
