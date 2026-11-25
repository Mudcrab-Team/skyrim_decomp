// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x1f3740 (skyrim_shared/forms/TESWeightForm): source copied, names replaced by placeholders.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Owner12a37f0: GUESS(low) STANDIN
// Owner12a37f0, Owner12a37f0::~Owner12a37f0, Owner12a37f0::InitializeDataComponent, Owner12a37f0::ClearDataComponent, Owner12a37f0::CopyComponent, weight, pad0C: GUESS(low) STANDIN
#pragma once
#include "TESWeightForm.h"

class Owner12a37f0 : public BaseFormComponent
{
public:
	~Owner12a37f0() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	float weight;  // 08
	std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(Owner12a37f0) == 0x10, "layout");
