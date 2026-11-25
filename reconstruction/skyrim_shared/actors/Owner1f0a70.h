// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Owner1f0a70: GUESS(low) STANDIN
// Owner1f0a70, Owner1f0a70::Owner1f0a70, Owner1f0a70::~Owner1f0a70, Owner1f0a70::InitializeDataComponent, Owner1f0a70::ClearDataComponent, Owner1f0a70::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Owner1f0a70 : public BaseFormComponent
{
public:
	Owner1f0a70();
	~Owner1f0a70() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Owner1f0a70) == 0x10, "layout");
