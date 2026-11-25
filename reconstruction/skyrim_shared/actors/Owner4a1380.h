// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Owner4a1380: GUESS(low) STANDIN
// Owner4a1380, Owner4a1380::Owner4a1380, Owner4a1380::~Owner4a1380, Owner4a1380::InitializeDataComponent, Owner4a1380::ClearDataComponent, Owner4a1380::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Owner4a1380 : public BaseFormComponent
{
public:
	Owner4a1380();
	~Owner4a1380() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Owner4a1380) == 0x10, "layout");
