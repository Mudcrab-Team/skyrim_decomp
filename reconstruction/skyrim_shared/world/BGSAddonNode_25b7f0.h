// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BGSAddonNode, BGSAddonNode::InitializeData, ::index, ::pad6C, ::sound, ::data, ::pad7C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ADDON_DATA, ADDON_DATA::masterParticleCap, ADDON_DATA::flags, ADDON_DATA::pad3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); flags is an enum of one byte in NG, a plain byte here
// unknown08: GUESS(low); padding up to the members NG declares
#pragma once

#include <cstddef>
#include <cstdint>

class BGSSoundDescriptorForm;

extern "C" void* memset(void* a_dst, int a_value, std::size_t a_size);

struct ADDON_DATA
{
	std::uint16_t masterParticleCap;  // 0
	std::uint8_t  flags;              // 2
	std::uint8_t  pad3;               // 3
};
static_assert(sizeof(ADDON_DATA) == 0x4, "ADDON_DATA size");

class BGSAddonNode
{
public:
	virtual void InitializeData();

	std::uint8_t            unknown08[0x60];  // 08
	std::uint32_t           index;            // 68
	std::uint32_t           pad6C;            // 6C
	BGSSoundDescriptorForm* sound;            // 70
	ADDON_DATA              data;             // 78
	std::uint32_t           pad7C;            // 7C
};
static_assert(sizeof(BGSAddonNode) == 0x80, "BGSAddonNode size");
