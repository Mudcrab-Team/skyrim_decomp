// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function155ea0: GUESS(low)
// Record155ea0: GUESS(low)
#pragma once

#include <cstdint>

struct Record155ea0
{
    std::uint64_t key;
    std::uint32_t id;
    std::uint32_t unk0C;
    float weight;
};

bool Function155ea0(const Record155ea0* lhs, const Record155ea0* rhs);
