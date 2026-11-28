// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Entry1047ea0, Container1047ea0, Function1047ea0: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct Entry1047ea0
{
    std::uint32_t key;    // 0x00
    std::uint32_t unk04;  // 0x04
    std::uint64_t unk08;  // 0x08
};

struct Container1047ea0
{
    std::uint64_t unk00[23];  // 0x00
    Entry1047ea0* entries;    // 0xB8
    std::int32_t count;       // 0xC0
};

bool Function1047ea0(const Container1047ea0* a_container, std::uint32_t a_key);  // compared: 0x1047ea0
