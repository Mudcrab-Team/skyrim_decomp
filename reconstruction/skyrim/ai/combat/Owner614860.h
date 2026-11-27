// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1df190 (skyrim/ai/combat/TESAttackDamageForm): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
// Function614860, Owner614860: GUESS(low) STANDIN
// Owner614860, Owner614860::~Owner614860, Owner614860::Owner614860, Owner614860::InitializeDataComponent, Owner614860::ClearDataComponent, Owner614860::CopyComponent, Owner614860::GetAttackDamage, attackDamage, unk0A: GUESS(low) STANDIN
#pragma once
#include "TESAttackDamageForm.h"

class Owner614860 : public ::BaseFormComponent
{
public:
	Owner614860();
	~Owner614860() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent() override;  // 03
	virtual std::uint16_t GetAttackDamage() const;  // 04
	void Function614860(std::uint16_t a_value);

	unsigned char padTwin8[94];
	std::uint16_t attackDamage;  // 08
	std::uint8_t unk0A[6];  // 0A
};
static_assert(sizeof(Owner614860) == 0x70, "layout");
