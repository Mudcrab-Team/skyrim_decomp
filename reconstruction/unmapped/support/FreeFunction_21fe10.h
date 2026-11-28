// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// FlagEntry21fe10, FlagOwner21fe10, Function21fe10: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct FlagEntry21fe10
{
    std::uint8_t flag;   // 0x00
    std::uint8_t unk01;  // 0x01
    std::uint16_t id;    // 0x02
};

struct FlagOwner21fe10
{
    std::uint64_t unk00[17];  // 0x00
    std::uint32_t count;      // 0x88
    std::uint32_t unk8C;      // 0x8C
    FlagEntry21fe10* entries; // 0x90
    std::uint8_t anyFlag;     // 0x98
};

void Function21fe10(FlagOwner21fe10* a_owner, std::uint16_t a_id, std::uint8_t a_value);  // compared: 0x21fe10
