// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x1dee90 (skyrim_shared/forms/TESAIForm): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
// Functionff3b30, Ownerff3b30: GUESS(low) STANDIN
// Ownerff3b30, Ownerff3b30::Ownerff3b30, Ownerff3b30::~Ownerff3b30, Ownerff3b30::InitializeDataComponent, Ownerff3b30::ClearDataComponent, Ownerff3b30::CopyComponent, Ownerff3b30::Function1dee20, Ownerff3b30::Function1dee90, aiData, aiPackages: GUESS(low) STANDIN
#pragma once
#include "TESAIForm.h"
#include <cstring>

class Ownerff3b30 : public ::BaseFormComponent
{
public:
	Ownerff3b30();

	~Ownerff3b30() override;  // 00, compared: 0x1df010
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
	std::uint16_t Function1dee20(std::uint32_t a_index) const;
	void Functionff3b30();

	AIDATA_GAME aiData;  // 08
	PackageList aiPackages;  // 18
};
static_assert(sizeof(Ownerff3b30) == 0x28, "layout");
