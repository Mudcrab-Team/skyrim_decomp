// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x1f3740 (skyrim_shared/forms/TESWeightForm): source copied, names replaced by placeholders.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Ownereaf0c0: GUESS(low) STANDIN
// Ownereaf0c0, Ownereaf0c0::~Ownereaf0c0, Ownereaf0c0::InitializeDataComponent, Ownereaf0c0::ClearDataComponent, Ownereaf0c0::CopyComponent, weight, pad0C: GUESS(low) STANDIN
#pragma once
#include "TESWeightForm.h"

class Ownereaf0c0 : public BaseFormComponent
{
public:
	~Ownereaf0c0() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	float weight;  // 08
	std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(Ownereaf0c0) == 0x10, "layout");
