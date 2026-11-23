// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESNPC, TESNPC::IsHeadPartAvailable, TESRace, BGSHeadPart::IsValidForRace, IsBitClear: GUESS(low) STANDIN
// BGSHeadPart::flags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares an enumeration over uint8
// TESNPC::IsFemale: CRASHLOGGER_PDB(59818@2026.10.24)
// IsFemale return type: OBSERVED; the callee result is only compared with zero
// race: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; offset and name only
#pragma once

#include <cstdint>
#include <cstddef>

struct TESRace;

// flag-word clear-bit test taking the word and bit index by value (cookbook rule 16)
inline bool IsBitClear(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return (~(a_flags >> a_bit) & 1) != 0;
}

struct BGSHeadPart
{
    bool IsValidForRace(TESRace* a_race) const;

    std::uint8_t pad00[0x68];
    std::int8_t flags;  // 68
};

class TESNPC
{
public:
    std::int32_t IsFemale() const;
    bool IsHeadPartAvailable(BGSHeadPart* a_headPart);  // compared: 0x3bfc00

    std::uint8_t pad00[0x158];
    TESRace* race;  // 158
};
