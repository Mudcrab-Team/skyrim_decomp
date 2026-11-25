// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1df190 (skyrim/ai/combat/TESAttackDamageForm): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
// Function5e84c0, Owner5e84c0: GUESS(low) STANDIN
// Owner5e84c0, Owner5e84c0::~Owner5e84c0, Owner5e84c0::Owner5e84c0, Owner5e84c0::InitializeDataComponent, Owner5e84c0::ClearDataComponent, Owner5e84c0::CopyComponent, Owner5e84c0::GetAttackDamage, attackDamage, unk0A: GUESS(low) STANDIN
#pragma once
#include "TESAttackDamageForm.h"

class Owner5e84c0 : public ::BaseFormComponent
{
public:
	Owner5e84c0();
	~Owner5e84c0() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent() override;  // 03
	virtual std::uint16_t GetAttackDamage() const;  // 04
	void Function5e84c0(std::uint16_t a_value);

	std::uint16_t attackDamage;  // 08
	std::uint8_t unk0A[6];  // 0A
};
static_assert(sizeof(Owner5e84c0) == 0x10, "layout");
