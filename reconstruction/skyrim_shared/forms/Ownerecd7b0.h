// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x190a90 (skyrim_shared/forms/TESFullName_190a90): source copied, names replaced by placeholders.
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Functionecd7b0, Ownerecd7b0: GUESS(low) STANDIN
// Function190b00, Function190b40, Function190b80, Function190bc0, Function190bd0, flags10, word12, Ownerecd7b0, Ownerecd7b0::~Ownerecd7b0, Ownerecd7b0::InitializeDataComponent, Ownerecd7b0::ClearDataComponent, Ownerecd7b0::CopyComponent, Ownerecd7b0::GetFullNameLength, Ownerecd7b0::GetFullName, fullName: GUESS(low) STANDIN
#pragma once
#include "TESFullName_190a90.h"

class Ownerecd7b0 : public BaseFormComponent
{
public:
	~Ownerecd7b0() override;  // 00
	void InitializeDataComponent() override;  // 01
	void ClearDataComponent() override;  // 02
	void CopyComponent() override;  // 03
	virtual std::uint32_t GetFullNameLength() const;  // 04
	virtual const char* GetFullName() const;  // 05

	const char* Functionecd7b0() const;
	std::uint8_t Function190b00() const;
	std::uint8_t Function190b40() const;
	std::uint8_t Function190b80() const;
	std::uint16_t Function190bc0() const;
	void Function190bd0(std::uint8_t a_value);

	BSFixedString fullName;  // 08
	std::uint8_t flags10;  // 10
	std::uint16_t word12;  // 12
};
static_assert(sizeof(Ownerecd7b0) == 0x18, "layout");
