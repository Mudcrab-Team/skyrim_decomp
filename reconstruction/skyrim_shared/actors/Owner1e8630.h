// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Owner1e8630: GUESS(low) STANDIN
// Owner1e8630, Owner1e8630::Owner1e8630, Owner1e8630::~Owner1e8630, Owner1e8630::InitializeDataComponent, Owner1e8630::ClearDataComponent, Owner1e8630::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Owner1e8630 : public BaseFormComponent
{
public:
	Owner1e8630();
	~Owner1e8630() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Owner1e8630) == 0x10, "layout");
