// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1df190 (skyrim/ai/combat/TESAttackDamageForm): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
// Functionb2fc40, Ownerb2fc40: GUESS(low) STANDIN
// Ownerb2fc40, Ownerb2fc40::~Ownerb2fc40, Ownerb2fc40::Ownerb2fc40, Ownerb2fc40::InitializeDataComponent, Ownerb2fc40::ClearDataComponent, Ownerb2fc40::CopyComponent, Ownerb2fc40::GetAttackDamage, attackDamage, unk0A: GUESS(low) STANDIN
#pragma once
#include "TESAttackDamageForm.h"

class Ownerb2fc40 : public ::BaseFormComponent
{
public:
	Ownerb2fc40();
	~Ownerb2fc40() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent() override;  // 03
	virtual std::uint16_t GetAttackDamage() const;  // 04
	void Functionb2fc40(std::uint16_t a_value);

	unsigned char padTwin8[22];
	std::uint16_t attackDamage;  // 08
	std::uint8_t unk0A[6];  // 0A
};
static_assert(sizeof(Ownerb2fc40) == 0x28, "layout");
