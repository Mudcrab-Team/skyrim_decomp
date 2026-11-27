// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Calendar: GUESS(low)
// Calendar::Function646160: GUESS(low)
// Calendar::unk30: GUESS(low)
// LinkedFields646160: STANDIN GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class LinkedFields646160
{
public:
    std::uint8_t unknown00[52];
    float unk34;
};
class Calendar
{
public:
    float Function646160();
    std::uint8_t unknown00[48];
    LinkedFields646160* unk30;
};
static_assert(offsetof(Calendar, unk30) == 48, "field offset");
