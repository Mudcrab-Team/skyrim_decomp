// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x190a90 (skyrim_shared/forms/TESFullName_190a90): source copied, names replaced by placeholders.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Function15a0910, Owner15a0910: GUESS(low) STANDIN
// Function190b00, Function190b40, Function190b80, Function190bc0, Function190bd0, flags10, word12, Owner15a0910, Owner15a0910::~Owner15a0910, Owner15a0910::InitializeDataComponent, Owner15a0910::ClearDataComponent, Owner15a0910::CopyComponent, Owner15a0910::GetFullNameLength, Owner15a0910::GetFullName, fullName: GUESS(low) STANDIN
#pragma once
#include "TESFullName_190a90.h"

class Owner15a0910 : public BaseFormComponent
{
public:
	~Owner15a0910() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent() override;  // 03
	virtual std::uint32_t GetFullNameLength() const;  // 04
	virtual const char* GetFullName() const;  // 05

	const char* Function15a0910() const;
	std::uint8_t Function190b00() const;
	std::uint8_t Function190b40() const;
	std::uint8_t Function190b80() const;
	std::uint16_t Function190bc0() const;
	void Function190bd0(std::uint8_t a_value);

	BSFixedString fullName;  // 08
	std::uint8_t flags10;  // 10
	std::uint16_t word12;  // 12
};
static_assert(sizeof(Owner15a0910) == 0x18, "layout");
