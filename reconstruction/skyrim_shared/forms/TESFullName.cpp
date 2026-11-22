// Source exposure: mixed (community headers; the pinned image listing).
// 0x190bd0 compared function
// 0x190bc0 compared function
// 0x190b80 compared function
// 0x190b40 compared function
// 0x190b00 compared function
// 0x190a90 compared function
// Code origin: SKELETON_TODO_CODE_ORIGIN (state the actual origin and any adaptation)
// SPDX-License-Identifier: CC0-1.0
// 0x190b50 TESFullName::Function190b50
// Adapted bodies: SKELETON_TODO_ORIGIN (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; these bodies reconstructed from the pinned image listing (others from the existing unit)
// SPDX-License-Identifier: CC0-1.0
// 0x190b10 TESFullName::Function190b10
// 0x190b50 TESFullName::Function190b50
// Adapted bodies: none
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from the local instruction listing of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
#include "TESFullName.h"

const char* TESFullName::Function190a90() const
{
    return GetFullName();
}

std::uint8_t TESFullName::Function190b00() const
{
    std::uint8_t v = flags10; return v & 1;
}

void TESFullName::Function190b10(bool a_flag)
{
    std::uint8_t v = flags10;
    std::uint8_t set = static_cast<std::uint8_t>(v | 1);
    std::uint8_t clear = static_cast<std::uint8_t>(v & 0xFE);
    if (a_flag)
        flags10 = set;
    else
        flags10 = clear;
}

void TESFullName::Function190b50(bool a_flag)
{
    std::uint8_t v = flags10;
    std::uint8_t set = static_cast<std::uint8_t>(v | 2);
    std::uint8_t clear = static_cast<std::uint8_t>(v & 0xFD);
    if (a_flag)
        flags10 = set;
    else
        flags10 = clear;
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
