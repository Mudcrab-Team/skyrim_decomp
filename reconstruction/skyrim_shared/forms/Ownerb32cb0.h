// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x1dee90 (skyrim_shared/forms/TESAIForm): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
// Functionb32cb0, Ownerb32cb0: GUESS(low) STANDIN
// Ownerb32cb0, Ownerb32cb0::Ownerb32cb0, Ownerb32cb0::~Ownerb32cb0, Ownerb32cb0::InitializeDataComponent, Ownerb32cb0::ClearDataComponent, Ownerb32cb0::CopyComponent, Ownerb32cb0::Function1dee20, Ownerb32cb0::Function1dee90, aiData, aiPackages: GUESS(low) STANDIN
#pragma once
#include "TESAIForm.h"
#include <cstring>

class Ownerb32cb0 : public ::BaseFormComponent
{
public:
	Ownerb32cb0();

	~Ownerb32cb0() override;  // 00, compared: 0x1df010
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
	std::uint16_t Function1dee20(std::uint32_t a_index) const;
	void Functionb32cb0();

	AIDATA_GAME aiData;  // 08
	PackageList aiPackages;  // 18
};
static_assert(sizeof(Ownerb32cb0) == 0x28, "layout");
