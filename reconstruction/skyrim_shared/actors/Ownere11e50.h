// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Ownere11e50: GUESS(low) STANDIN
// Ownere11e50, Ownere11e50::Ownere11e50, Ownere11e50::~Ownere11e50, Ownere11e50::InitializeDataComponent, Ownere11e50::ClearDataComponent, Ownere11e50::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Ownere11e50 : public BaseFormComponent
{
public:
	Ownere11e50();
	~Ownere11e50() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Ownere11e50) == 0x10, "layout");
