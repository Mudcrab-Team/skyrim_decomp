// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x146a50 (skyrim_shared/forms/BGSEquipType): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
// Owner43e4e0: GUESS(low) STANDIN
// Owner43e4e0, Owner43e4e0::~Owner43e4e0, Owner43e4e0::Owner43e4e0, Owner43e4e0::InitializeDataComponent, Owner43e4e0::ClearDataComponent, Owner43e4e0::CopyComponent, Owner43e4e0::GetEquipSlot, Owner43e4e0::SetEquipSlot, equipSlot: GUESS(low) STANDIN
#pragma once
#include "BGSEquipType.h"

class Owner43e4e0 : public ::BaseFormComponent
{
public:
	Owner43e4e0();
	// the listing inlines the complete destructor (the base teardown stores its vftable), so the body is empty
	~Owner43e4e0() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent() override;  // 03
	virtual BGSEquipSlot* GetEquipSlot() const;  // 04
	virtual void SetEquipSlot(BGSEquipSlot* a_slot);  // 05

	BGSEquipSlot* equipSlot;  // 08
};
static_assert(sizeof(Owner43e4e0) == 0x10, "layout");
