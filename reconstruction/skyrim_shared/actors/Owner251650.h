// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Owner251650: GUESS(low) STANDIN
// Owner251650, Owner251650::Owner251650, Owner251650::~Owner251650, Owner251650::InitializeDataComponent, Owner251650::ClearDataComponent, Owner251650::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Owner251650 : public BaseFormComponent
{
public:
	Owner251650();
	~Owner251650() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Owner251650) == 0x10, "layout");
