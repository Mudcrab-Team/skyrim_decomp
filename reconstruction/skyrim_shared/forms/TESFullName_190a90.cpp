// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; these bodies are written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x190a90 TESFullName::Function190a90
// 0x190b00 TESFullName::Function190b00
// 0x190b40 TESFullName::Function190b40
// 0x190b80 TESFullName::Function190b80
// 0x190bc0 TESFullName::Function190bc0
// 0x190bd0 TESFullName::Function190bd0
// Adapted bodies: none
#include "TESFullName_190a90.h"

const char* TESFullName::Function190a90() const
{
    return GetFullName();
}

std::uint8_t TESFullName::Function190b00() const
{
    std::uint8_t v = flags10; return v & 1;
}

std::uint8_t TESFullName::Function190b40() const
{
    std::uint8_t v = flags10; v >>= 1; return v & 1;
}

std::uint8_t TESFullName::Function190b80() const
{
    std::uint8_t v = flags10; v >>= 2; return v & 1;
}

std::uint16_t TESFullName::Function190bc0() const
{
    return word12;
}

void TESFullName::Function190bd0(std::uint8_t a_value)
{
    word12 = a_value;
}

void TESFullName::ClearDataComponent()
{
}

std::uint32_t TESFullName::GetFullNameLength() const
{
    return BSFixedStringLength(&fullName);
}

const char* TESFullName::GetFullName() const
{
    return fullName.data();
}
