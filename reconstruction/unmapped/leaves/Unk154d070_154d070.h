// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk154d070: STANDIN GUESS(low)
// Unk154d070::Function154d070: GUESS(low)
// Unk154d070::flag, Unk154d070::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class Unk154d070
{
public:
    void* Function154d070();
    std::uint8_t unknown0[31];
    std::uint8_t flag;
    std::uint8_t unknown20[24];
    void* value;
};
static_assert(offsetof(Unk154d070, flag) == 31, "field offset");
static_assert(offsetof(Unk154d070, value) == 56, "field offset");
