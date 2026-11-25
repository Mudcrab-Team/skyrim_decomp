// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1ef710 (skyrim_shared/actors/TESRaceForm): source copied, names replaced by placeholders.
// Owner128a990: GUESS(low) STANDIN
// Owner128a990, Owner128a990::Owner128a990, Owner128a990::~Owner128a990, Owner128a990::InitializeDataComponent, Owner128a990::ClearDataComponent, Owner128a990::CopyComponent, race: GUESS(low) STANDIN
#pragma once
#include "TESRaceForm.h"

class Owner128a990 : public BaseFormComponent
{
public:
	Owner128a990();
	~Owner128a990() override {}  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03

	TESRace* race;  // 08
};
static_assert(sizeof(Owner128a990) == 0x10, "layout");
