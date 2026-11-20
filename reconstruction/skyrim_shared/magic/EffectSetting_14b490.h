// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// EffectSetting, GetObjectTypeName, archetype: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); archetype is data.archetype at 0x68 + 0x58
// ArchetypeInfo, g_archetypeInfo, name, unk08, unk10: GUESS(low); a global table of 24-byte records indexed by archetype, the name first
#pragma once

#include <cstdint>

struct ArchetypeInfo
{
	const char*   name;   // 00
	std::uint64_t unk08;  // 08
	std::uint64_t unk10;  // 10
};
static_assert(sizeof(ArchetypeInfo) == 0x18, "layout");

extern ArchetypeInfo g_archetypeInfo[];

class EffectSetting
{
public:
	const char* GetObjectTypeName() const;

	std::uint8_t unk00[0xC0];  // 00
	std::int32_t archetype;    // C0
};
