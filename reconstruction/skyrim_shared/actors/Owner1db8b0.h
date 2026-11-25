// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Owner1db8b0: GUESS(low) STANDIN
// Owner1db8b0, Owner1db8b0::Owner1db8b0, Owner1db8b0::~Owner1db8b0, Owner1db8b0::InitializeDataComponent, Owner1db8b0::ClearDataComponent, Owner1db8b0::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Owner1db8b0 : public BaseFormComponent
{
public:
	Owner1db8b0();
	~Owner1db8b0() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Owner1db8b0) == 0x10, "layout");
