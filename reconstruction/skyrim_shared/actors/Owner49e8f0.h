// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Owner49e8f0: GUESS(low) STANDIN
// Owner49e8f0, Owner49e8f0::Owner49e8f0, Owner49e8f0::~Owner49e8f0, Owner49e8f0::InitializeDataComponent, Owner49e8f0::ClearDataComponent, Owner49e8f0::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Owner49e8f0 : public BaseFormComponent
{
public:
	Owner49e8f0();
	~Owner49e8f0() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Owner49e8f0) == 0x10, "layout");
