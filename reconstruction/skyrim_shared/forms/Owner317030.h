// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0x1e88f0 (skyrim_shared/forms/TESLeveledList): source copied, names replaced by placeholders.
// Owner317030: GUESS(low) STANDIN
// Owner317030, Owner317030::~Owner317030, Owner317030::InitializeDataComponent, Owner317030::ClearDataComponent, Owner317030::CopyComponent, Owner317030::GetChanceNone, Owner317030::GetMultCalc, Owner317030::GetLevDifferenceMax, Owner317030::GetCanContainFormsOfType, GetUseAll, entries, chanceNone, llFlags, numEntries, unk13, pad14, unk18, chanceGlobal: GUESS(low) STANDIN
#pragma once
#include "TESLeveledList.h"

class Owner317030 : public BaseFormComponent
{
public:
	~Owner317030() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent(BaseFormComponent* a_rhs) override;  // 03
	virtual std::uint8_t GetChanceNone();  // 04
	virtual bool GetMultCalc();  // 05
	virtual std::int32_t GetLevDifferenceMax();  // 06
	virtual bool GetCanContainFormsOfType(std::uint8_t a_type) const = 0;  // 07
	bool GetUseAll();

	LEVELED_OBJECT* entries;  // 08
	std::int8_t chanceNone;  // 10
	unsigned char padTwin11[39];
	std::uint8_t llFlags;  // 11
	std::uint8_t numEntries;  // 12
	std::uint8_t unk13;  // 13
	std::uint32_t pad14;  // 14
	void* unk18;  // 18
	TESGlobal* chanceGlobal;  // 20
};
static_assert(sizeof(Owner317030) == 0x50, "layout");
