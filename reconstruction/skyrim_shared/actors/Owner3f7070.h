// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Owner3f7070: GUESS(low) STANDIN
// Owner3f7070, Owner3f7070::Owner3f7070, Owner3f7070::~Owner3f7070, Owner3f7070::InitializeDataComponent, Owner3f7070::ClearDataComponent, Owner3f7070::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Owner3f7070 : public BaseFormComponent
{
public:
	Owner3f7070();
	~Owner3f7070() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Owner3f7070) == 0x10, "layout");
