// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x1dee90 (skyrim_shared/forms/TESAIForm): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BaseFormComponent: STANDIN EXE_RTTI COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only class names, base chain,
// slot order and sizes are claimed.
// Function4a73e0, Owner4a73e0: GUESS(low) STANDIN
// Owner4a73e0, Owner4a73e0::Owner4a73e0, Owner4a73e0::~Owner4a73e0, Owner4a73e0::InitializeDataComponent, Owner4a73e0::ClearDataComponent, Owner4a73e0::CopyComponent, Owner4a73e0::Function1dee20, Owner4a73e0::Function1dee90, aiData, aiPackages: GUESS(low) STANDIN
#pragma once
#include "TESAIForm.h"
#include <cstring>

class Owner4a73e0 : public ::BaseFormComponent
{
public:
	Owner4a73e0();

	~Owner4a73e0() override;  // 00, compared: 0x1df010
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
	std::uint16_t Function1dee20(std::uint32_t a_index) const;
	void Function4a73e0();

	AIDATA_GAME aiData;  // 08
	PackageList aiPackages;  // 18
};
static_assert(sizeof(Owner4a73e0) == 0x28, "layout");
