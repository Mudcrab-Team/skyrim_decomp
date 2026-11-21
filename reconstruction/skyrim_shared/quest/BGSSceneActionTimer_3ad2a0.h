// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BGSSceneAction, BGSSceneActionTimer, Unk_0B, timerSeconds, unk24: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk28: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares one 64-bit member here, the image clears two adjacent bytes with one 16-bit store
// unk29: GUESS(low)
#pragma once

#include <cstdint>

class BGSSceneAction
{
public:
	virtual void Unk_0B();

	std::uint8_t unk08[0x18];  // 08
};

class BGSSceneActionTimer : public BGSSceneAction
{
public:
	void Unk_0B() override;

	float         timerSeconds;  // 20
	std::uint32_t unk24;         // 24
	bool          unk28;         // 28
	bool          unk29;         // 29
	std::uint16_t pad2A;         // 2A
	std::uint32_t pad2C;         // 2C
};
static_assert(sizeof(BGSSceneActionTimer) == 0x30, "layout");
